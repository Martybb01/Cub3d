/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:20:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/08/03 10:35:48 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_err(char *msg, int err_code)
{
	ft_putstr_fd("cub3d: Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(err_code);
	return (0);
}
