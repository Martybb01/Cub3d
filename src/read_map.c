/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:49:39 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/24 15:49:11 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_read_map(char *path, t_var *var)
{
	int		fd;
	char	*line;
	char	*buffer;
	int		i;
	int		line_length;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(3, var);
	buffer = ft_strdup("");
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (ft_blank_line(line))
			i++;
		if (i > 6)
		{
			buffer = ft_strfjoin(buffer, line);
			line_length = ft_strlen(line);
			if (line_length > var->map.width)
				var->map.width = line_length;
			var->map.height++;
		}
		free(line);
	}
	close(fd);
	var->map.map = ft_split(buffer, '\n');
	free(buffer);
}
