/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freesca <freesca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:19:11 by freesca           #+#    #+#             */
/*   Updated: 2024/09/03 19:21:57 by freesca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_player_dir(t_var *var, int i, int j)
{
    if (var->map.map[i][j] == 'N')
        var->player.dir = 90;
    if (var->map.map[i][j] == 'S')
        var->player.dir = 270;
    if (var->map.map[i][j] == 'E')
        var->player.dir = 0;
    if (var->map.map[i][j] == 'W')
        var->player.dir = 180;
    var->map.map[i][j] = '0';
}

void	ft_player_init(t_var *var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < var->map.height)
	{
		j = -1;
		while (++j < (int )ft_strlen(var->map.map[i]))
		{
			if (var->map.map[i][j] == 'N' || var->map.map[i][j] == 'S'
				|| var->map.map[i][j] == 'E' || var->map.map[i][j] == 'W')
			{
				var->player.point.x = j * TILESIZE;
				var->player.point.y = i * TILESIZE;
                ft_player_dir(var, i, j);
				return ;
			}
		}
	}
}
