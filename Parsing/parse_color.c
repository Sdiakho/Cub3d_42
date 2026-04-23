/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:09:24 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/23 16:11:09 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_com(char *str)
{
	int i;
	int com;

	i = 0;
	com = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ',')
		{
			com += 1;
			if (str[i + 1] && (str[i + 1] < '0' || str[i + 1] > '9'))
				return (0);		
		}
		i++;
	}
	if (com == 2)
		return (1);
	return (0);
}

int	decompose(char **tab, int *r, int *g, int *b)
{
	*r = 0;
	*g = 0;
	*b = 0;
	if (!ft_atoi(tab[0], r))
		return (0);
	if (!ft_atoi(tab[1], g))
		return (0);
	if (!ft_atoi(tab[2], b))
		return (0);
	return (1);
}

void	recombine_ceil(t_cub *cub, int r, int g, int b)
{
	cub->rgb_ceil = (r << 16) | (g << 8) | b;
}

void	recombine_floor(t_cub *cub, int r, int g, int b)
{
	cub->rgb_floor = (r << 16) | (g << 8) | b;
}

int	fill_rgb(t_cub *cub)
{
	char	**floor;
	char	**ceil;
	int		r;
	int		g;
	int		b;

	if (!check_com(cub->ceil))
		return (0);
	if (!check_com(cub->floor))
		return (0);
	floor = ft_split(cub->floor, ",");
	if (!floor)
		return (0);
	ceil = ft_split(cub->ceil, ",");
	if (!ceil)
		return (free_split(floor), 0);
	if (!decompose(ceil, &r, &g, &b))
		return (free_split(floor), free_split(ceil), 0);
	recombine_ceil(cub, r, g, b);
	if (!decompose(floor, &r, &g, &b))
		return (free_split(floor), free_split(ceil), 0);
	recombine_floor(cub, r, g, b);
	free_split(floor);
	free_split(ceil);
	return (1);
}
