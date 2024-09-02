/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:18:31 by freesca           #+#    #+#             */
/*   Updated: 2024/09/02 12:34:30 by freesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(t_var *var)
{
	if (var->player.rot == 1)
	{
		if (var->player.dir + (1 + SPEED) > 360)
			var->player.dir = var->player.dir - 360;
		var->player.dir += (1 + SPEED);
	}
	if (var->player.rot == -1)
	{
		if (var->player.dir - (1 + SPEED) < 0)
			var->player.dir = 360 + var->player.dir;
		var->player.dir -= (1 + SPEED);
	}
}

void    ft_load_player(t_var *var)
{
    ft_rotate(var);
    ft_move(var);
}