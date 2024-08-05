/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:39:31 by marboccu          #+#    #+#             */
/*   Updated: 2024/08/05 19:37:05 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_is_within_bounds(int value, int min, int max)
{
	return (value >= min && value < max);
}

void ft_normalize(double *value, int min, int max)
{
	if (*value < min)
		*value = min;
	if (*value >= max)
		*value = max - 1;
}

void ft_draw_tex_pixel(t_draw_text *dt)
{
	int color;
	color = *(int *)(dt->texture->addr + (dt->tex_y * dt->texture->line_length + dt->tex_x * (dt->texture->bpp / 8)));
	*(int *)(dt->img->addr + (int)(dt->y * dt->img->line_length + dt->x * (dt->img->bpp / 8))) = color;
}

void ft_draw_tex_column(t_draw_text *dt)
{
	int y;
	double step;
	double tex_pos;
	int line_height;

	y = dt->start.y;
	line_height = dt->end.y - dt->start.y;

	step = 1.0 * dt->texture->height / line_height;
	tex_pos = (dt->start.y - HEIGHT / 2 + line_height / 2) * step;

	while (y < dt->end.y)
	{
		dt->tex_y = (int)tex_pos;
		if (ft_is_within_bounds(dt->tex_y, 0, dt->texture->height))
		{
			dt->y = y;
			ft_draw_tex_pixel(dt);
		}
		tex_pos += step;
		y++;
	}
}

void ft_draw_tex(t_pimg *img, t_point start, t_point end, t_texture *texture, int tex_x)
{
	t_draw_text dt;

	if (!ft_is_within_bounds(tex_x, 0, texture->width))
		return ;

	ft_normalize(&start.y, 0, HEIGHT - 1);
	ft_normalize(&end.y, 0, HEIGHT - 1);

	dt.img = img;
	dt.texture = texture;
	dt.start = start;
	dt.end = end;
	dt.tex_x = tex_x;
	dt.x = start.x;
	dt.y = start.y;
	dt.tex_y = 0;

	ft_draw_tex_column(&dt);
}

// void ft_draw_tex(t_pimg *img, t_point start, t_point end, t_texture *texture, int tex_x)
// {
// 	int y;
// 	int tex_y;
// 	double step;
// 	double tex_pos;
// 	int line_height;
// 	int color;

// 	if (tex_x < 0 || tex_x >= texture->width)
// 		return ;
// 	if (start.y < 0) start.y = 0;
// 	if (end.y >= HEIGHT) end.y = HEIGHT - 1;

// 	line_height = end.y - start.y;
// 	step = 1.0 * texture->height / line_height;
// 	tex_pos = (start.y - HEIGHT / 2 + line_height / 2) * step;
// 	y = start.y;
// 	while (y < end.y)
// 	{
// 		tex_y = (int)tex_pos;
// 		if (tex_y >= 0 && tex_y < texture->width)
// 		{
// 		tex_pos += step;
// 		color = *(int *)(texture->addr + (tex_y * texture->line_length + tex_x * (texture->bpp / 8)));
// 		if (y >= 0 && y < HEIGHT)
// 			*(int *)(img->addr + (int)(y * img->line_length + start.x * (img->bpp / 8))) = color;
// 		}
// 		y++;
// 	}
// }
