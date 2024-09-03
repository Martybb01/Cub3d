/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:35:57 by freesca           #+#    #+#             */
/*   Updated: 2024/09/03 13:37:43 by freesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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