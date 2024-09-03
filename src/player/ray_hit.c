/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:12:44 by freesca           #+#    #+#             */
/*   Updated: 2024/09/03 13:41:52 by freesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		return (NORTH);
	else
		return (SOUTH);
}
void    ft_ray_hit_x(t_point *hit_point, t_ray *ray, t_point delta_point, double dir_angle)
{
    hit_point->y -= delta_point.y;
    if (dir_angle >= 90 && dir_angle <= 270)
        ft_ray_hit_corr1(hit_point, dir_angle);
    else
        ft_ray_hit_corr2(hit_point, dir_angle);
    ray->side = ft_ray_side_x(delta_point);
    ray->hit_tile = (int)hit_point->y % TILESIZE;
}

void    ft_ray_hit_y(t_point *hit_point, t_ray *ray, t_point delta_point, double dir_angle)
{
    if (dir_angle >= 0 && dir_angle <= 180)
        ft_ray_hit_corr3(hit_point, dir_angle);
    else
        ft_ray_hit_corr4(hit_point, dir_angle);
    ray->side = ft_ray_side_y(delta_point);
    ray->hit_tile = (int)hit_point->x % TILESIZE;
}

t_point	ft_ray_hit(t_var *var, t_point delta_point, t_ray *ray, double dir_angle)
{
	t_point	hit_point;

	hit_point.x = var->player.point.x;
	hit_point.y = var->player.point.y;
	while (1)
	{
		hit_point.x += delta_point.x;
		if (ft_hit_wall(var, hit_point, delta_point))
		{
            ft_ray_hit_x(&hit_point, ray, delta_point, dir_angle);
			break ;
		}
		hit_point.y -= delta_point.y;
		if (ft_hit_wall(var, hit_point, delta_point))
		{
            ft_ray_hit_y(&hit_point, ray, delta_point, dir_angle);
			break ;
		}
	}
	return (hit_point);
}
