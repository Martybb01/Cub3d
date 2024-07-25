/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:55:16 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/25 18:49:28 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_var *var, int keycode)
{
	double	delta_x;
	double	delta_y;

	delta_x = cos(var->player.dir * M_PI / 180) * SPEED;
	delta_y = sin(var->player.dir * M_PI / 180) * SPEED;
	if (keycode == W)
	{
		if (var->map.map[(int)(var->player.point->y + delta_y) / TILESIZE]
			[(int)(var->player.point->x + delta_x) / TILESIZE] == '0')
		{
			var->player.point->x += delta_x;
			var->player.point->y += delta_y;
		}
	}
	if (keycode == S)
	{
		if (var->map.map[(int)(var->player.point->y - delta_y) / TILESIZE]
			[(int)(var->player.point->x - delta_x) / TILESIZE] == '0')
		{
			var->player.point->x -= delta_x;
			var->player.point->y -= delta_y;
		}
	}
	if (keycode == A)
	{
		if (var->map.map[(int)(var->player.point->y - delta_x) / TILESIZE]
			[(int)(var->player.point->x + delta_y) / TILESIZE] == '0')
		{
			var->player.point->x += delta_y;
			var->player.point->y -= delta_x;
		}
	}
	if (keycode == D)
	{
		if (var->map.map[(int)(var->player.point->y + delta_x) / TILESIZE]
			[(int)(var->player.point->x - delta_y) / TILESIZE] == '0')
		{
			var->player.point->x -= delta_y;
			var->player.point->y += delta_x;
		}
	}
}

void	ft_rotate(t_var *var, int keycode)
{
	if (keycode == LEFT)
	{
		if (var->player.dir - (1 + SPEED) < 0)
			var->player.dir = 360 + var->player.dir;
		var->player.dir -= (1 + SPEED);
	}
	if (keycode == RIGHT)
	{
		if (var->player.dir + (1 + SPEED) > 360)
			var->player.dir = var->player.dir - 360;
		var->player.dir += (1 + SPEED);
	}
}

int	ft_key_press(int keycode, t_var *var)
{
	/* if (keycode == ESC)
		ft_destroy_game(var); */
	if (keycode == LEFT || keycode == RIGHT)
		ft_rotate(var, keycode);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		ft_move(var, keycode);
	return (0);
}
