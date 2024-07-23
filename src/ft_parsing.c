/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:00:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/07/23 18:06:27 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_check_file(int ac, char *file)
{
	if (ac != 2)
		ft_error(1, NULL);
	else if (!ft_match_ext(file, ".cub"))
		ft_error(3, NULL);
	return (0);
}
