/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:53:30 by marboccu          #+#    #+#             */
/*   Updated: 2024/08/06 17:14:33 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_draw_texture(t_var *var, t_ray *ray, t_tex_params *tex_params)
{
	if (ray->side == NORTH)
		ft_draw_tex(&var->img, tex_params->start, tex_params->end, &var->pars.no, tex_params->tex_x);
	else if (ray->side == SOUTH)
		ft_draw_tex(&var->img, tex_params->start, tex_params->end, &var->pars.so, tex_params->tex_x);
	else if (ray->side == EAST)
		ft_draw_tex(&var->img, tex_params->start, tex_params->end, &var->pars.ea, tex_params->tex_x);
	else if (ray->side == WEST)
		ft_draw_tex(&var->img, tex_params->start, tex_params->end, &var->pars.we, tex_params->tex_x);
}

void ft_raycaster(t_var *var)
{
	t_ray_params context;
	t_tex_params tex_params;
	
	context.var = var;
	context.point.x = 0;
	context.ray_angle = -1 - (FOV / 2);
	context.delta_angle = FOV / WIDTH;

	while (context.point.x < WIDTH)
	{
		context.ray = ft_ray(context.var, context.ray_angle);
		ft_compute_tex_params(&context, &tex_params);

		if ((int)context.point.x % 1 == 0)
			ft_draw_texture(var, &context.ray, &tex_params);
		context.point.x++;
		context.ray_angle = context.ray_angle + context.delta_angle;
	}
}

t_point	ft_opp_point(t_point point)
{
	t_point	opp;

	opp.x = point.x;
	opp.y = HEIGHT - point.y;
	return (opp);
}


//TODO: fatta un altra ma sul modello del tuo raycast iniziale, questa x ora boh teniamola qui
/* void	ft_ray_casting(t_var *var)
{
	double	ray_angle;
	double	delta_angle;
	t_point	point;
	t_ray	ray;

	point.x = 0;
	ray_angle =  (FOV / 2);
	delta_angle = (double) FOV / WIDTH;
	while (point.x < WIDTH)
	{
		ray = ft_ray(var, ray_angle);
		point.y = HEIGHT / 2 + ((double) TILESIZE * HEIGHT)
			/ (ray.dist * cos(ray_angle * M_PI / 180));

		if ((int )point.x % 1 == 0)
		{
			if (ray.side == NORTH)
				ft_draw_line(&var->img, point, ft_opp_point(point), GREEN);
			else if (ray.side == SOUTH)
				ft_draw_line(&var->img, point, ft_opp_point(point), BLACK);
			else if (ray.side == EAST)
				ft_draw_line(&var->img, point, ft_opp_point(point), YELLOW);
			else if (ray.side == WEST)
				ft_draw_line(&var->img, point, ft_opp_point(point), GRAY);
		}
		point.x++;
		ray_angle = ray_angle - delta_angle;
		if (ray_angle > -3 && ray_angle < 3)
			printf("ray_angle = %f\n", ray_angle);
	}
} */
