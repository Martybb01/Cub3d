/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:02:28 by fdonati           #+#    #+#             */
/*   Updated: 2024/08/06 19:43:32 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	ft_ray_delta(t_var *var, double ray_angle)
{
	double	dir_angle;
	t_point	delta_point;

	dir_angle = var->player.dir + ray_angle;
	while (dir_angle < 0)
		dir_angle += 360;
	while (dir_angle > 360)
		dir_angle -= 360;
	delta_point.x = cos(dir_angle * M_PI / 180);
	delta_point.y = sin(dir_angle * M_PI / 180);
	return (delta_point);
}

t_side	ft_ray_side_x(t_point delta_point)
{
	if (delta_point.x > 0)
		return (EAST);
	else
		return (WEST);
}

t_side	ft_ray_side_y(t_point delta_point)
{
	if (delta_point.y > 0)
		return (SOUTH);
	else
		return (NORTH);
}

t_point	ft_ray_hit(t_var *var, t_point delta_point, t_ray *ray)
{
	t_point	hit_point;

	hit_point.x = var->player.point.x;
	hit_point.y = var->player.point.y;
	while (1)
	{
		hit_point.x += delta_point.x;
		if (var->map.map[(int)floor(hit_point.y / TILESIZE)]
			[(int)floor(hit_point.x / TILESIZE)] == '1')
		{
			hit_point.x -= delta_point.x;
			hit_point.x = floor(hit_point.x);
			ray->side = ft_ray_side_x(delta_point);
			break ;
		}
		hit_point.y += delta_point.y;
		if (var->map.map[(int)floor(hit_point.y / TILESIZE)]
			[(int)floor(hit_point.x / TILESIZE)] == '1')
		{
			hit_point.y = floor(hit_point.y);
			ray->side = ft_ray_side_y(delta_point);
			break ;
		}
	}
	return (hit_point);
}

t_ray	ft_ray(t_var *var, double ray_angle)
{
	t_point	delta_point;
	t_point	hit_point;
	t_ray	ray;

	delta_point = ft_ray_delta(var, ray_angle);
	hit_point = ft_ray_hit(var, delta_point, &ray);
	ft_draw_line(&var->img, var->player.point, hit_point, RED);
	ray.dist = sqrt(pow(var->player.point.x - hit_point.x, 2)
			+ pow(var->player.point.y - hit_point.y, 2));
	return (ray);
}
