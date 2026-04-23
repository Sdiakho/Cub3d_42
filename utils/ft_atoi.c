/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:59:16 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/23 14:41:43 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_space(char c)
{
	return ((c == ' ') || (c >= 9 && c <= 13));
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str, int *out)
{
	int	res;

	if (!str || !out)
		return (0);
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			return (0);
	if (!is_digit(*str))
		return (0);
	res = 0;
	while (is_digit(*str))
	{
		res = res * 10 + (*str++ - '0');
		if (res > 255)
			return (0);
	}
	while (is_space(*str))
		str++;
	if (*str)
		return (0);
	return (*out = (res), 1);
}
