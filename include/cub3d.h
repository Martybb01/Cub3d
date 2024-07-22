/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:54:18 by fdonati           #+#    #+#             */
/*   Updated: 2024/07/22 15:26:30 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/keysymdef.h>

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_var;

#endif