/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:42:19 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/26 17:42:04 by fdonati          ###   ########.fr       */
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
	int	color;

	y = -1;
	while (++y < var->map.height)
	{
		x = -1;
		while (++x < (int )ft_strlen(var->map.map[y]))
		{
			if (var->map.map[y][x] == '1')
				color = GRAY;
			if (var->map.map[y][x] == '0')
				color = WHITE;
			ft_draw_tile(&var->img, x * TILESIZE, y * TILESIZE, color);
		}
	}
}

/* void	ft_render_dir(t_var *var)
{
	int		x;
	int		y;
	t_point	pointv;

	x = var->player.point.x;
	y = var->player.point.y;
	pointv.x = x + cos(var->player.dir * M_PI / 180) * TILESIZE;
	pointv.y = y + sin(var->player.dir * M_PI / 180) * TILESIZE;
	ft_draw_line(&var->img, var->player.point, pointv, BLACK);
} */

void	ft_render_player(t_var *var)
{
	ft_draw_tile(&var->img, var->player.point.x - TILESIZE / 2,
		var->player.point.y - TILESIZE / 2, RED);
	/* ft_render_dir(var); */
}

int	ft_load_game(t_var *var)
{
	ft_render_map(var);
	ft_render_player(var);
	printf("dist: %d\n", ft_ray(var, 0));
	ft_ray(var, -30);
	ft_ray(var, 30);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	//ft_print_map(var->map);
	return (0);
}
