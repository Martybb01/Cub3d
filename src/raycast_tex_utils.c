/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_tex_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:53:37 by marboccu          #+#    #+#             */
/*   Updated: 2024/08/06 15:06:12 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double ft_compute_wall_dist(t_ray_params *context)
{
	double wall_dist;

	wall_dist = context->ray.dist * cos(context->ray_angle * M_PI / 180);
	if (wall_dist <= 0)
		wall_dist = 0.1;
	return (wall_dist);
}

void ft_compute_wall_intersec(t_ray_params *context, t_tex_params *tex_params, double wall_dist)
{
	if (context->ray.side == EAST || context->ray.side == WEST)
		tex_params->wall_x = context->var->player.point.y + wall_dist * sin(context->ray_angle * M_PI / 180);
	else
		tex_params->wall_x = context->var->player.point.x + wall_dist * cos(context->ray_angle * M_PI / 180);
	tex_params->wall_x -= floor(tex_params->wall_x);
}

void ft_compute_tex_coord(t_ray_params *context, t_tex_params *tex_params, double wall_dist)
{
	tex_params->tex_x = (int)(tex_params->wall_x * (double)context->var->pars.no.width);
	if (context->ray.side == EAST || context->ray.side == WEST) 
		tex_params->tex_x = context->var->pars.ea.width - tex_params->tex_x - 1;
	
	tex_params->start.x = context->point.x;
	tex_params->start.y = HEIGHT / 2 - (TILESIZE * HEIGHT) / (2 * wall_dist);
	tex_params->end.x = context->point.x;
	tex_params->end.y = HEIGHT / 2 + (TILESIZE * HEIGHT) / (2 * wall_dist);

	 if (tex_params->start.y < 0)
        tex_params->start.y = 0;
    if (tex_params->end.y >= HEIGHT)
        tex_params->end.y = HEIGHT - 1;
}

void ft_compute_tex_params(t_ray_params *context, t_tex_params *tex_params)
{
	double wall_dist;

	wall_dist = ft_compute_wall_dist(context);
	context->point.y = HEIGHT / 2 + (TILESIZE * HEIGHT) / wall_dist;
	if (context->point.y < 0)
		context->point.y = 0;
    if (context->point.y >= HEIGHT)
		context->point.y = HEIGHT - 1;
	ft_compute_wall_intersec(context, tex_params, wall_dist);
	ft_compute_tex_coord(context, tex_params, wall_dist);
}

