/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:02:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/04 12:25:00 by marboccu         ###   ########.fr       */
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
		return (ft_err(BAD_ARG), 1);
	else if (!ft_match_ext(file, ".cub"))
		return (ft_err(EXT_ERROR), 1);
	return (0);
}

void	ft_trim_leadblank(char *str)
{
	char	*start;

	start = str;
	while (*start && ft_isspace(*start))
		start++;
	if (start != str)
		ft_memmove(str, start, ft_strlen(start) + 1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_check_unique_player(char *row)
{
	int	i;
	int	player_count;

	i = -1;
	player_count = 0;
	while (row[++i])
	{
		if (ft_strchr("NSWE", row[i]))
			player_count++;
	}
	return (player_count);
}

/* void	ft_print_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
	{
		ft_putstr_fd(map.map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
} */
