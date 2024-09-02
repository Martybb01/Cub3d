/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:53:30 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/02 11:19:12 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tex_color(t_texture texture, t_point tex)
{
	int	color;
	int	x;
	int	y;

	x = (int)tex.x;
	y = (int)tex.y;

	if (x < 0 || x >= texture.width || y < 0 || y >= texture.height)
		return (0);
	color = *(int *)(texture.addr + (y * texture.line_length + x * (texture.bpp / 8)));
	return (color);
}

t_texture	ft_define_texture(t_var *var, t_ray ray)
{
	if (ray.side == NORTH)
		return (var->pars.no);
	else if (ray.side == SOUTH)
		return (var->pars.so);
	else if (ray.side == EAST)
		return (var->pars.ea);
	else
		return (var->pars.we);
}

void    ft_draw_texture2(t_var *var, int x, t_ray ray, int wall_height)
{
	t_point		tex;
	t_texture	texture;
	int			y;
    double		scale;

	texture = ft_define_texture(var, ray);
	scale = (double)texture.height / wall_height;
	tex.x = ((double)ray.hit_tile / TILESIZE) * texture.width;
	tex.y = 0;
	y = (HEIGHT / 2 - wall_height / 2);
	while (y < (HEIGHT / 2 + wall_height / 2))
	{
		if (y == HEIGHT / 2)
			printf("tex.x: %f, tex.y: %f\n", tex.x, tex.y);
		ft_draw_pixel(&var->img, x, y, ft_tex_color(texture, tex));
		tex.y += scale;
		y += 1;
	}
}

void	ft_ray_casting(t_var *var)
{
	double	ray_angle;
	double	delta_angle;
    int     wall_height;
	t_point	point;
	t_ray	ray;

	point.x = 0;
	ray_angle =  (FOV / 2);
	delta_angle = (double) FOV / WIDTH;
	while (point.x < WIDTH)
	{
		ray = ft_ray(var, ray_angle);
		point.y = HEIGHT / 2 + ((double) TILESIZE * HEIGHT)
			/ (ray.dist * cos(ray_angle * M_PI / 180));
        wall_height = (TILESIZE * HEIGHT) / (ray.dist * cos(ray_angle * M_PI / 180));
		ft_draw_texture2(var, (int)point.x, ray, wall_height);
		point.x++;
		ray_angle = ray_angle - delta_angle;
	}
}
