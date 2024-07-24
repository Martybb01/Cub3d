/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:00:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/07/24 16:11:45 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file(int ac, char *file)
{
	(void)file;
	if (ac != 2)
		ft_error(1, NULL);
	else if (!ft_match_ext(file, ".cub"))
		ft_error(3, NULL);
	return (0);
}
