/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:05:09 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/04 12:24:09 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_trim_newl(char *line, char **trim)
{
	char	*tmp;
	int		len;

	tmp = ft_strtrim(line + 2, " \t");
	if (!tmp)
		return (1);
	len = ft_strlen(tmp);
	if (len > 0 && tmp[len - 1] == '\n')
		tmp[len - 1] = '\0';
	*trim = tmp;
	return (0);
}

int	ft_parse_color(char *line, t_rgb *color)
{
	char	*tmp;
	char **rgb;

	if (ft_trim_newl(line, &tmp))
		return (1);
	rgb = ft_split(tmp, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (ft_free_matrix(rgb), free(tmp), ft_err(BAD_COLOR), 1);
	if (!ft_isdigit(rgb[0][0]) || !ft_isdigit(rgb[1][0]) || !ft_isdigit(rgb[2][0]))
		return (ft_free_matrix(rgb), free(tmp), ft_err(BAD_COLOR), 1);
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) < 0 || 
		ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255)
		return (ft_free_matrix(rgb), free(tmp), ft_err(BAD_COLOR), 1);
	
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);

	ft_free_matrix(rgb);
	free(tmp);
	return (0);
}

int	ft_parse_texture(char *line, t_texture *texture, t_var *var)
{
	char	*tmp;

	if (ft_trim_newl(line, &tmp))
		return (1);

	if (texture->img)
	{
		mlx_destroy_image(var->mlx, texture->img);
		texture->img = NULL;
	}
	texture->img = mlx_xpm_file_to_image(var->mlx, tmp, &texture->width, &texture->height);
	free(tmp);
	 if (!texture->img)
	 	return (ft_err(BAD_TEXTURE), 1);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_length, &texture->endian);
	if (!texture->addr)
		return (ft_err(BAD_ADDR), 1);
	return (0);
}
