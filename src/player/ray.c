/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:02:28 by fdonati           #+#    #+#             */
/*   Updated: 2024/09/03 13:33:01 by freesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	ft_ray_delta(double dir_angle)
{
	t_point	delta_point;

	delta_point.x = cos(dir_angle * M_PI / 180);
	delta_point.y = sin(dir_angle * M_PI / 180);
	return (delta_point);
}

t_ray	ft_ray(t_var *var, double ray_angle)
{
	t_point	delta_point;
	t_point	hit_point;
	t_ray	ray;
	double	dir_angle;

	dir_angle = var->player.dir + ray_angle;
	while (dir_angle < 0)
		dir_angle += 360;
	while (dir_angle > 360)
		dir_angle -= 360;
	delta_point = ft_ray_delta(dir_angle);
	hit_point = ft_ray_hit(var, delta_point, &ray, dir_angle);
	ray.dist = sqrt(pow(var->player.point.x - hit_point.x, 2)
			+ pow(var->player.point.y - hit_point.y, 2));
	return (ray);
}
