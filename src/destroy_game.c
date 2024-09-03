/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:44:33 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/03 16:28:37 by freesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_map(char **map, int height)
{
	int	i;

	i = -1;
	while (++i < height)
	{
		free(map[i]);
	}
	return (0);
}

int	ft_free_all(t_var *var)
{
	if (var->map.map)
	{
		ft_free_map(var->map.map, var->map.height);
		free(var->map.map);
	}
	if (var->pars.no.img)
		mlx_destroy_image(var->mlx, var->pars.no.img);
	if (var->pars.so.img)
		mlx_destroy_image(var->mlx, var->pars.so.img);
	if (var->pars.ea.img)
		mlx_destroy_image(var->mlx, var->pars.ea.img);
	if (var->pars.we.img)
		mlx_destroy_image(var->mlx, var->pars.we.img);
	if (var->img.img)
		mlx_destroy_image(var->mlx, var->img.img);
	return (0);
}

int	ft_destroy_game(t_var *var)
{
	if (var->mlx && var->win)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	if (var->mlx)
	{
		// mlx_destroy_display(var->mlx);
		// mlx_loop_end(var->mlx);
		free(var->mlx);
	}
	ft_free_all(var);
	exit(0);
}
