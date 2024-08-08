/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:53:37 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/28 17:11:00 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_forward(t_var *var, double delta_x, double delta_y)
{
	if (var->map.map[(int)(var->player.point.y + delta_y) / TILESIZE]
		[(int)(var->player.point.x + delta_x) / TILESIZE] == '0')
	{
		var->player.point.x += delta_x;
		var->player.point.y -= delta_y;
	}
}

void	ft_move_backward(t_var *var, double delta_x, double delta_y)
{
	if (var->map.map[(int)(var->player.point.y - delta_y) / TILESIZE]
		[(int)(var->player.point.x - delta_x) / TILESIZE] == '0')
	{
		var->player.point.x -= delta_x;
		var->player.point.y += delta_y;
	}
}

void	ft_move_left(t_var *var, double delta_x, double delta_y)
{
	if (var->map.map[(int)(var->player.point.y - delta_x) / TILESIZE]
		[(int)(var->player.point.x + delta_y) / TILESIZE] == '0')
	{
		var->player.point.x -= delta_y;
		var->player.point.y -= delta_x;
	}
}

void	ft_move_right(t_var *var, double delta_x, double delta_y)
{
	if (var->map.map[(int)(var->player.point.y + delta_x) / TILESIZE]
		[(int)(var->player.point.x - delta_y) / TILESIZE] == '0')
	{
		var->player.point.x += delta_y;
		var->player.point.y += delta_x;
	}
}

void	ft_move(t_var *var, int keycode)
{
	double	delta_x;
	double	delta_y;

	delta_x = cos(var->player.dir * M_PI / 180) * SPEED;
	delta_y = sin(var->player.dir * M_PI / 180) * SPEED;
	if (keycode == W)
		ft_move_forward(var, delta_x, delta_y);
	if (keycode == S)
		ft_move_backward(var, delta_x, delta_y);
	if (keycode == A)
		ft_move_left(var, delta_x, delta_y);
	if (keycode == D)
		ft_move_right(var, delta_x, delta_y);
}
