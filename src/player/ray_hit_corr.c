/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_corr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:34:36 by freesca           #+#    #+#             */
/*   Updated: 2024/09/03 13:35:03 by freesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_hit_corr1(t_point *hit_point, double dir_angle)
{
	double	c;
	double	hit_round;

	hit_round = ceil(hit_point->x);
	c = hit_round - hit_point->x;
	if (dir_angle <= 180)
		hit_point->y = hit_point->y + fabs(c * tan(dir_angle * M_PI / 180));
	else if (dir_angle >= 180)
	hit_point->y = hit_point->y - fabs(c * tan(dir_angle * M_PI / 180));
	hit_point->x = hit_round;
}
void	ft_ray_hit_corr2(t_point *hit_point, double dir_angle)
{
	double	c;
	double	hit_round;

	hit_round = floor(hit_point->x);
	c = hit_point->x - hit_round;
	if (dir_angle <= 90)
		hit_point->y = hit_point->y + fabs(c * tan(dir_angle * M_PI / 180));
	else if (dir_angle >= 270)
		hit_point->y = hit_point->y - fabs(c * tan(dir_angle * M_PI / 180));
	hit_point->x = hit_round;
}
void	ft_ray_hit_corr3(t_point *hit_point, double dir_angle)
{
	double	c;
	double	hit_round;

	hit_round = ceil(hit_point->y);
	c = hit_round - hit_point->y;
	if (dir_angle <= 90)
		hit_point->x = hit_point->x - fabs(c * (1 / tan(dir_angle * M_PI / 180)));
	else if (dir_angle >= 90)
		hit_point->x = hit_point->x + fabs(c * (1 / tan(dir_angle * M_PI / 180)));
	hit_point->y = hit_round;
}

void	ft_ray_hit_corr4(t_point *hit_point, double dir_angle)
{
	double	c;
	double	hit_round;

	hit_round = floor(hit_point->y);
	c = hit_point->y - hit_round;
	if (dir_angle <= 270)
		hit_point->x = hit_point->x + fabs(c * (1 / tan(dir_angle * M_PI / 180)));
	else if (dir_angle >= 270)
		hit_point->x = hit_point->x - fabs(c * (1 / tan(dir_angle * M_PI / 180)));
	hit_point->y = hit_round;
}