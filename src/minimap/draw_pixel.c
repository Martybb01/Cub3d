/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:53:42 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/25 18:51:49 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_pixel(t_pimg *img, int x, int y, int color)
{
	char	*dst;

	/* if (x < 0 || x > 1280 || y < 0 || y >= 720) 
		return ; */ //TODO : capire se sono necessari i controlli
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
