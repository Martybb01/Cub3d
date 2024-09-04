/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:51:10 by fdonati           #+#    #+#             */
/*   Updated: 2024/09/04 12:30:09 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO: norminette me plz

int	main(int argc, char **argv)
{
	t_var	var;

	var.win = NULL;
	var.img.img = NULL;
	var.img.addr = NULL;
	var.mlx = NULL;
	var.map = (t_map){0};
	var.player = (t_plyr){0};
	var.pars = (t_pars){0};
	ft_check_file(argc, argv[1]);
	var.path = argv[1];
	var.mlx = mlx_init();
	if (!var.mlx)
		return (ft_err(MLX_ERROR), 1);
	if (ft_read_map(var.path, &var))
		return (ft_err(MAP_ERROR), ft_destroy_game(&var, 1), 1);
	if (!ft_parse_map(&var))
		return (ft_err(MAP_ERROR), ft_destroy_game(&var, 1), 1);
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "cub3d");
	if (!var.win)
		return (ft_err(WIN_ERROR), ft_destroy_game(&var, 1), 1);
	var.img.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	var.img.addr = mlx_get_data_addr(var.img.img, &var.img.bpp,
					&var.img.line_length, &var.img.endian);
	ft_player_init(&var);
	ft_key_handler(&var);
	mlx_loop_hook(var.mlx, &ft_load_game, &var);
	mlx_loop(var.mlx);
}
