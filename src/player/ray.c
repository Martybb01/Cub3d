/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:02:28 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/26 17:42:11 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_ray(t_var *var, int angle)
{
	double	delta_x;
	double	delta_y;
	t_point	point;
	int		new_angle;

	new_angle = var->player.dir + angle;
	while (new_angle < 0)
		new_angle += 360;
	while (new_angle > 360)
		new_angle -= 360;
	delta_x = cos(new_angle * M_PI / 180);
	delta_y = sin(new_angle * M_PI / 180);
	point.x = var->player.point.x;
	point.y = var->player.point.y;
	while (var->map.map[(int)point.y / TILESIZE]
		[(int)point.x / TILESIZE] != '1')
	{
		point.x += delta_x;
		point.y += delta_y;
	}
	ft_draw_line(&var->img, var->player.point, point, RED);
	return (sqrt(pow(var->player.point.x - point.x, 2)
			+ pow(var->player.point.y - point.y, 2)));
}
