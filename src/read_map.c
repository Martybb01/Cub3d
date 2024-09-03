/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:49:39 by fdonati           #+#    #+#             */
/*   Updated: 2024/09/03 16:40:07 by freesca          ###   ########.fr       */
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

//TODO: norminette me plz
int	ft_parse_color(char *line, t_rgb *color)
{
	char	*tmp;
	int		len;
	char	**rgb;

	tmp = ft_strtrim(line + 2, " \t");
	if (!tmp)
		return (1);
	len = ft_strlen(tmp);
	if (len > 0 && tmp[len - 1] == '\n')
		tmp[len - 1] = '\0';
	rgb = ft_split(tmp, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		ft_err(BAD_COLOR, 1);
	if (!ft_isdigit(rgb[0][0])
		|| !ft_isdigit(rgb[1][0]) || !ft_isdigit(rgb[2][0]))
		ft_err(BAD_COLOR, 1);
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) < 0
		|| ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255)
		ft_err(BAD_COLOR, 1);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	ft_free_matrix(rgb);
	free(tmp);
	return (0);
}

//TODO: norminette me plz
int	ft_parse_texture(char *line, t_texture *texture, t_var *var)
{
	char	*tmp;
	int		len;

	tmp = ft_strtrim(line + 2, " \t");
	if (!tmp)
		return (1);
	len = ft_strlen(tmp);
	if (len > 0 && tmp[len - 1] == '\n')
		tmp[len - 1] = '\0';
	if (texture->img)
	{
		mlx_destroy_image(var->mlx, texture->img);
		texture->img = NULL;
	}
	texture->img = mlx_xpm_file_to_image(var->mlx, tmp,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		ft_printf(2, "Error loading XPM file: %s\n", tmp);
		free(tmp);
		return (1);
	}
	free(tmp);
	if (!texture->img)
		return (1);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
		return (1);
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

//TODO: norminette me plz
int	ft_read_map(char *path, t_var *var)
{
	int		fd;
	char	*line;
	char	*buffer;
	int		i;
	int		line_length;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_err(FILE_ERROR, 1));
	buffer = ft_strdup("");
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (ft_check_options(line, var) == 1)
			return (ft_err(BAD_OPTION, 1));
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
	return (0);
}
