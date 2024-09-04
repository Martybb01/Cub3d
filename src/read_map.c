/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:49:39 by fdonati           #+#    #+#             */
/*   Updated: 2024/09/04 12:05:41 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <ctype.h>

static int	ft_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" \t\n\v\f\r", line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_options(char *line, t_var *var)
{
	if (line[0] == 'F')
		return (ft_parse_color(line, &var->pars.floor));
	if (line[0] == 'C')
		return (ft_parse_color(line, &var->pars.ceiling));
	if (line[0] == 'N' && line[1] == 'O')
		return (ft_parse_texture(line, &var->pars.no, var));
	if (line[0] == 'S' && line[1] == 'O')
		return (ft_parse_texture(line, &var->pars.so, var));
	if (line[0] == 'W' && line[1] == 'E')
		return (ft_parse_texture(line, &var->pars.we, var));
	if (line[0] == 'E' && line[1] == 'A')
		return (ft_parse_texture(line, &var->pars.ea, var));
	return (0);
}

int ft_validate_line(char *line, t_var *var, char **buffer, int *i)
{
    if (ft_check_options(line, var) == 1)
        return (ft_err(BAD_OPTION), 1);

    if (ft_blank_line(line))
        (*i)++;

    if (*i > 6)
    {
        *buffer = ft_strfjoin(*buffer, line);
        int line_length = ft_strlen(line);
        if (line_length > var->map.width)
            var->map.width = line_length;
        var->map.height++;
    }
    return (0);
}

int ft_process_lines(int fd, t_var *var, char **buffer)
{
    char *line;
    int i = 0;

    while (1)
    {
        line = ft_get_next_line(fd);
        if (!line)
            break;

        if (ft_validate_line(line, var, buffer, &i) != 0)
            return (free(line), 1);
        free(line);
    }

    return 0;
}

//TODO: norminette me plz
int	ft_read_map(char *path, t_var *var)
{
	int		fd;
	char	*buffer;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_err(FILE_ERROR), 1);
	buffer = ft_strdup("");
	if (ft_process_lines(fd, var, &buffer) != 0)
		return (free(buffer), 1);
	close(fd);
	var->map.map = ft_split(buffer, '\n');
	free(buffer);
	return (0);
}
