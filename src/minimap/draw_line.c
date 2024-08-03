/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:04:00 by fdonati           #+#    #+#             */
/*   Updated: 2024/08/02 12:25:06 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_line(t_pimg *img, t_point p1, t_point p2, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	x;
	int	y;
	int	err;

	dx = abs((int )p2.x - (int )p1.x);
	dy = abs((int )p2.y - (int )p1.y);
	err = dx - dy;
	if (p1.x < p2.x)
		sx = 1;
	else
		sx = -1;
	if (p1.y < p2.y)
		sy = 1;
	else
		sy = -1;
	x = (int )p1.x;
	y = (int )p1.y;
	while (1)
	{
		ft_draw_pixel(img, x, y, color);
		if (x == (int )p2.x && y == (int )p2.y)
			break ;
		if (-dy < 2 * err)
		{
			err -= dy;
			x += sx;
		}
		else if (dx > 2 * err)
		{
			err += dx;
			y += sy;
		}
	}
}

//TODO : norminette
