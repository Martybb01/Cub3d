/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:02:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/07/28 19:49:20 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_match_ext(char *map, char *ext)
{
	int	map_len;
	int	ext_len;

	map_len = ft_strlen(map);
	ext_len = ft_strlen(ext);
	if (map_len < ext_len)
		return (0);
	map += map_len - ext_len;
	while (*map)
	{
		if (*map != *ext)
			return (0);
		map++;
		ext++;
	}
	return (1);
}

int	ft_check_file(int ac, char *file)
{
	(void)file;
	if (ac != 2)
		ft_error(1, NULL);
	else if (!ft_match_ext(file, ".cub"))
		ft_error(3, NULL);
	return (0);
} 

void ft_trim_leadblank(char *str)
{
	char *start;

	start = str;
	while (*start && ft_isspace(*start))
		start++;
	if (start != str)
		ft_memmove(str, start, ft_strlen(start) + 1);
}
