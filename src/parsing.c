/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:00:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/03 13:08:58 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_real_rowlen(char *row)
{
	int len;

	len = ft_strlen(row);
	while (len > 0 && ft_isspace(row[len - 1]))
		len--;
	return (len);
}

int ft_check_firstlast(char *row)
{
	int i;

	i = -1;
	while (row[++i])
	{
		if (row[i] != '1' && !ft_isspace(row[i]))
			return (0);
	}
	return (1);
}

int ft_check_middles(char *row)
{
	int i;
	int len;
	static int player_count = 0;

	len = ft_real_rowlen(row);
	if (row[0] != '1' || row[len - 1] != '1')
		return (0);
	i = -1;
	while (row[++i])
	{
		if (!ft_strchr(" 012NSWE", row[i]))
			return (0);
		if (ft_isspace(row[i]))
		{
			if ((i > 0 && row[i - 1] != '1' && !ft_isspace(row[i - 1])) ||
			    (i < len - 1 && row[i + 1] != '1' && !ft_isspace(row[i + 1])))
				return (0);
		}
	}
	player_count += ft_check_unique_player(row);
	if (player_count > 1)
		return (0);
	return (1);
}

int check_row_lenghts(char *curr_row, char *next_row)
{
	int curr_len;
	int next_len;
	int i;

	curr_len = ft_real_rowlen(curr_row);
	next_len = ft_real_rowlen(next_row);
	if (next_len < curr_len)
	{
		i = next_len;
		while (i < curr_len)
		{
			if (curr_row[i] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

int ft_parse_map(t_var *var)
{
	int i;

	i = -1;
	while (++i < var->map.height)
	{
		ft_trim_leadblank(var->map.map[i]);
		if (i == 0 || i == var->map.height - 1)
		{
			if (!ft_check_firstlast(var->map.map[i]))
				return (0);
		}
		else
		{
			if (!ft_check_middles(var->map.map[i]))
				return (0);
		}
		if (i > 0 && !check_row_lenghts(var->map.map[i], var->map.map[i - 1])) 
			return 0;
		
		if (i < var->map.height - 1 && !check_row_lenghts(var->map.map[i], var->map.map[i + 1])) 
			return 0;
		
	}
	return (1);
}
