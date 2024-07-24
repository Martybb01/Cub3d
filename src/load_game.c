/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:42:19 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/24 17:10:13 by fdonati          ###   ########.fr       */
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

static void	ft_pixel_put(t_pimg *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_render_tile(t_pimg *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TILESIZE)
	{
		j = -1;
		while (++j < TILESIZE)
			ft_pixel_put(img, x + j, y + i, color);
	}
}

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
			ft_render_tile(&var->img, x * TILESIZE, y * TILESIZE, color);
		}
	}
}

void	ft_render_dir(t_var *var)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = var->player.x;
	y = var->player.y;
	i = x + cos(var->player.dir * M_PI / 180) * TILESIZE;
	j = y + sin(var->player.dir * M_PI / 180) * TILESIZE;
	while (x != i || y != j)
	{
		ft_pixel_put(&var->img, x, y, RED);
		x += cos(var->player.dir * M_PI / 180);
		y += sin(var->player.dir * M_PI / 180);
	}
}

void	ft_render_player(t_var *var)
{
	ft_render_dir(var);
	ft_render_tile(&var->img, var->player.x - TILESIZE / 2,
		var->player.y - TILESIZE / 2, RED);
}

int	ft_load_game(t_var *var)
{
	ft_render_map(var);
	ft_render_player(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	//ft_print_map(var->map);
	return (0);
}
