/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:51:10 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/23 16:08:45 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(int error, t_var *var)
{
	(void)var;
	if (error == 1)
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
	if (error == 2)
		ft_putstr_fd("Error: Mlx error\n", 2);
	if (error == 3)
		ft_putstr_fd("Error: Map error\n", 2);
	exit(error);
}

int	main(int argc, char **argv)
{
	t_var	var;

	var.map = (t_map){0};
	ft_check_file(argc, argv[1]);
	var.path = argv[1];
	var.mlx = mlx_init();
	if (!var.mlx)
		ft_error(2, &var);
	var.win = mlx_new_window(var.mlx, 1280, 720, "cub3d");
	if (!var.win)
		ft_error(2, &var);
	ft_read_map(var.path, &var);
	//ft_get_mapsize(var.map);
	mlx_loop_hook(var.mlx, &ft_load_game, &var);
	mlx_loop(var.mlx);
}
