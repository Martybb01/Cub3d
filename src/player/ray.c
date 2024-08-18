/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:02:28 by fdonati           #+#    #+#             */
/*   Updated: 2024/08/03 16:34:30 by fdonati          ###   ########.fr       */
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

int	ft_hit_wall(t_var *var, t_point hit_point, t_point delta_point)
{
	if (delta_point.y >= 0 && delta_point.x >= 0)
	{
		if (var->map.map[(int)ceil(hit_point.y) / TILESIZE]
			[(int)floor(hit_point.x) / TILESIZE] == '1')
			return (1);
	}
	if (delta_point.y >= 0 && delta_point.x <= 0)
	{
		if (var->map.map[(int)ceil(hit_point.y) / TILESIZE]
			[(int)ceil(hit_point.x) / TILESIZE] == '1')
			return (1);
	}
	if (delta_point.y <= 0 && delta_point.x <= 0)
	{
		if (var->map.map[(int)floor(hit_point.y) / TILESIZE]
			[(int)ceil(hit_point.x) / TILESIZE] == '1')
			return (1);
	}
	if (delta_point.y <= 0 && delta_point.x >= 0)
	{
		if (var->map.map[(int)floor(hit_point.y) / TILESIZE]
			[(int)floor(hit_point.x) / TILESIZE] == '1')
			return (1);
	}
	return (0);
}

t_point	ft_ray_hit(t_var *var, t_point delta_point, t_ray *ray, double dir_angle)
{
	t_point	hit_point;
	double	c;
	double	hit_round;

	hit_point.x = var->player.point.x;
	hit_point.y = var->player.point.y;
	while (1)
	{
		hit_point.x += delta_point.x;
		if (ft_hit_wall(var, hit_point, delta_point))
		{
			hit_point.y -= delta_point.y;
			if (dir_angle >= 90 && dir_angle <= 270)
			{
				hit_round = ceil(hit_point.x);
				c = hit_round - hit_point.x;
				if (dir_angle <= 180)
					hit_point.y = hit_point.y + fabs(c * tan(dir_angle * M_PI / 180));
				else if (dir_angle >= 180)
					hit_point.y = hit_point.y - fabs(c * tan(dir_angle * M_PI / 180));
				hit_point.x = hit_round;
			}
			else
			{
				hit_round = floor(hit_point.x);
				c = hit_point.x - hit_round;
				if (dir_angle <= 90)
					hit_point.y = hit_point.y + fabs(c * tan(dir_angle * M_PI / 180));
				else if (dir_angle >= 270)
					hit_point.y = hit_point.y - fabs(c * tan(dir_angle * M_PI / 180));
				hit_point.x = hit_round;
			}
			ray->side = ft_ray_side_x(delta_point);
			ray->hit_tile = (int)hit_point.y % TILESIZE;
			break ;
		}
		hit_point.y -= delta_point.y;
		if (ft_hit_wall(var, hit_point, delta_point))
		{
			if (dir_angle >= 0 && dir_angle <= 180)
			{
				hit_round = ceil(hit_point.y);
				c = hit_round - hit_point.y;
				if (dir_angle <= 90)
					hit_point.x = hit_point.x - fabs(c * (1 / tan(dir_angle * M_PI / 180)));
				else if (dir_angle >= 90)
					hit_point.x = hit_point.x + fabs(c * (1 / tan(dir_angle * M_PI / 180)));
				hit_point.y = hit_round;
			}
			else
			{
				hit_round = floor(hit_point.y);
				c = hit_point.y - hit_round;
				if (dir_angle <= 270)
					hit_point.x = hit_point.x + fabs(c * (1 / tan(dir_angle * M_PI / 180)));
				else if (dir_angle >= 270)
					hit_point.x = hit_point.x - fabs(c * (1 / tan(dir_angle * M_PI / 180)));
				hit_point.y = hit_round;
			}
			ray->side = ft_ray_side_y(delta_point);
			ray->hit_tile = (int)hit_point.x % TILESIZE;
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
	double	dir_angle;

	dir_angle = var->player.dir + ray_angle;
	while (dir_angle < 0)
		dir_angle += 360;
	while (dir_angle > 360)
		dir_angle -= 360;
	delta_point = ft_ray_delta(dir_angle);
	hit_point = ft_ray_hit(var, delta_point, &ray, dir_angle);
	ft_draw_line(&var->img, var->player.point, hit_point, RED);
	ray.dist = sqrt(pow(var->player.point.x - hit_point.x, 2)
			+ pow(var->player.point.y - hit_point.y, 2));
	return (ray);
}
