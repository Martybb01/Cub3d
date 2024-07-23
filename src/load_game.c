/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:42:19 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/23 11:55:43 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static void	ft_print_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
	{
		ft_putstr_fd(map.map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
} */

void	ft_render_map(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	while (var->map.map[x])
	{
		y = 0;
		while (var->map.map[x][y])
		{
			if (var->map.map[x][y] == '1')
				mlx_pixel_put(var->mlx, var->win, y, x, 0x00FF0000);
			if (var->map.map[x][y] == '0')
				mlx_pixel_put(var->mlx, var->win, y, x, 0x0000FF00);
			y++;
		}
		x++;
	}

}

int	ft_load_game(t_var *var)
{
	ft_render_map(var);
	//ft_print_map(var->map);
	return (0);
}