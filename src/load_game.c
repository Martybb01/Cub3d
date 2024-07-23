/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:42:19 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/23 18:14:27 by marboccu         ###   ########.fr       */
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
	int mini_x;
	int mini_y;

	y = -1;
	while (++y < var->map.y)
	{
		x = -1;
		while (++x < (int )ft_strlen(var->map.map[y]))
		{
			mini_x = x * TILESIZE;
			mini_y = y * TILESIZE;
			int i = -1;
			while (++i < TILESIZE)
			{
				int j = -1;
				while (++j < TILESIZE)
				{
					if (var->map.map[y][x] == '1')
						mlx_pixel_put(var->mlx, var->win, mini_x + j, mini_y + i, 0x00FF0000);
					if (var->map.map[y][x] == '0')
						mlx_pixel_put(var->mlx, var->win, mini_x + j, mini_y + i, 0x0000FF00);
				}
			}
		}
	}
}

int	ft_load_game(t_var *var)
{
	ft_render_map(var);
	//ft_print_map(var->map);
	return (0);
}
