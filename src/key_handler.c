/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:13:01 by freesca           #+#    #+#             */
/*   Updated: 2024/09/02 17:53:57 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int keycode, t_var *var)
{
	if (keycode == ESC)
		ft_destroy_game(var);
	if (keycode == W)
		var->player.move_x = 1;
	if (keycode == S)
		var->player.move_x = -1;
	if (keycode == A)
		var->player.move_y = 1;
	if (keycode == D)
		var->player.move_y = -1;
	if (keycode == LEFT)
		var->player.rot = 1;
	if (keycode == RIGHT)
		var->player.rot = -1;
	if (keycode == M)
		var->map.show = 1;
	return (0);
}

int    ft_key_release(int keycode, t_var *var)
{
    if (keycode == W)
		var->player.move_x += 1;
	if (keycode == S)
		var->player.move_x -= 1;
    if (keycode == A)
		var->player.move_y -= 1;
	if (keycode == D)
		var->player.move_y += 1;
    if (keycode == LEFT)
		var->player.rot = 0;
	if (keycode == RIGHT)
		var->player.rot = 0;
	if (keycode == M)
		var->map.show = 0;
	return (0);
}

void    ft_key_handler(t_var *var)
{
	mlx_hook(var->win, 17, 0, &ft_destroy_game, var);
    mlx_hook(var->win, 2, 1L << 0, &ft_key_press, var);
    mlx_hook(var->win, 3, 1L << 1, &ft_key_release, var);
}
