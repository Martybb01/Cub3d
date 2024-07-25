/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:50:36 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/25 18:50:50 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_tile(t_pimg *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TILESIZE)
	{
		j = -1;
		while (++j < TILESIZE)
			ft_draw_pixel(img, x + j, y + i, color);
	}
}
