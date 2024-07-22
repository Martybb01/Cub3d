/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:51:10 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/22 16:16:04 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_print_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
	{
		ft_putstr_fd(map.map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

static	void	ft_error(int error, t_var *var)
{
	(void)var;
	if (error == 1)
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
	if (error == 2)
		ft_putstr_fd("Error\nMlx error\n", 2);
	if (error == 3)
		ft_putstr_fd("Error\nMap error\n", 2);
	exit(error);
}

static int	ft_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" \t\n\v\f\r", line[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	ft_read_map(char *path, t_var *var)
{
	int		fd;
	char	*line;
	char	*buffer;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	buffer = ft_strdup("");
	if (fd == -1)
		ft_error(3, var);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (ft_blank_line(line))
			i++;
		if (i > 6)
			buffer = ft_strfjoin(buffer, line);
		free(line);
	}
	close(fd);
	var->map.map = ft_split(buffer, '\n');
	free(buffer);
}

int	main(int argc, char **argv)
{
	t_var	var;

	var.map = (t_map){0};
	if (argc != 2)
		ft_error(1, &var);
	var.mlx = mlx_init();
	if (!var.mlx)
		ft_error(2, &var);
	var.win = mlx_new_window(var.mlx, 800, 600, "cub3d");
	if (!var.win)
		ft_error(2, &var);
	ft_read_map(argv[1], &var);
	ft_print_map(var.map);
	mlx_loop(var.mlx);
}

//TODO: boh