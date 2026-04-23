/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:05:26 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/22 17:49:30 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_pl_pos(int *x, int *y, t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (is_pl_pos(cub->map[i][j]))
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

int flood_fill(t_cub *cub, int y, int x)
{
	if (x < 0 || y < 0 || y >= cub->height || x >= cub->width)
		return (1);
	if (cub->map[y][x] == '1' || cub->map[y][x] == 'V')
		return (0);
	if (cub->map[y][x] == 'F')
		return (1);
	cub->map[y][x] = 'V';
	if (flood_fill(cub, y + 1, x) == 1)
		return (1);
	if (flood_fill(cub, y - 1, x) == 1)
		return (1);
	if (flood_fill(cub, y, x + 1) == 1)
		return (1);
	if (flood_fill(cub, y, x - 1) == 1)
		return (1);
	return (0);
}

int check_flood(t_cub *cub)
{
	int x;
	int y;
	x = 0;
	y = 0;
	find_pl_pos(&x, &y, cub);
	if (flood_fill(cub, y, x) == 1)
		return (0);
	return (1);
}


void	restore_flood(t_cub *cub)
{
	int 	x;
	int 	y;
	int		i;
	t_list	*tmp;

	y = 0;
	tmp = cub->map_start;
	while (y < cub->height)
	{
		x = 0;
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == ' ')
			{
				i++;
				continue ;
			}
			if (cub->map[y][x] == 'F')
			{
				x++;
				continue;
			}
			cub->map[y][x] = tmp->line[i];
			x++;
			i++;
		}
		tmp = tmp->next;
		y++;
	}
}
