/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:42:19 by fdonati           #+#    #+#             */
/*   Updated: 2024/09/02 12:18:14 by freesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

//TODO: ci serve ancora pt.2 ?
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


void	ft_render_ceiling(t_var *var)
{
	int	x;
	int	y;
	int color;

	y = 0;
	while (y < HEIGHT / 2)
	{
		color = create_trgb(0, var->pars.ceiling.r, var->pars.ceiling.g, var->pars.ceiling.b);
		x = 0;
		while (x < WIDTH)
		{
			ft_draw_pixel(&var->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_render_floor(t_var *var)
{
	int	x;
	int	y;
	int color;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		color = create_trgb(0, var->pars.floor.r, var->pars.floor.g, var->pars.floor.b);
		x = 0;
		while (x < WIDTH)
		{
			ft_draw_pixel(&var->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_load_game(t_var *var)
{
	ft_load_player(var);
	ft_render_ceiling(var);
	ft_render_floor(var);
	ft_render_map(var);
	ft_render_player(var);
	/* ft_raycaster(var); */
	ft_ray_casting(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	//ft_print_map(var->map);
	return (0);
}
