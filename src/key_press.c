/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:55:16 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/28 17:14:30 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(t_var *var, int keycode)
{
	if (keycode == LEFT)
	{
		if (var->player.dir + (1 + SPEED) > 360)
			var->player.dir = var->player.dir - 360;
		var->player.dir += (1 + SPEED);
	}
	if (keycode == RIGHT)
	{
		if (var->player.dir - (1 + SPEED) < 0)
			var->player.dir = 360 + var->player.dir;
		var->player.dir -= (1 + SPEED);
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
