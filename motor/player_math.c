/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:28:32 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/22 18:01:00 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void find_player(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < cub->height)
	{
		j = 0;
		while (j < cub->width)
		{
			if (is_pl_pos(cub->map[i][j]))
			{
				cub->p1->pos_x = j;
				cub->p1->pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void fill_north(t_cub *cub)
{
	cub->p1->dir_x = 0;
	cub->p1->dir_y = -1;
	cub->p1->plane_x = 0.66;
	cub->p1->plane_y = 0;
}

void fill_south(t_cub *cub)
{
	cub->p1->dir_x = 0;
	cub->p1->dir_y = 1;
	cub->p1->plane_x = -0.66;
	cub->p1->plane_y = 0;
}

void fill_west(t_cub *cub)
{
	cub->p1->dir_x = -1;
	cub->p1->dir_y = 0;
	cub->p1->plane_x = 0;
	cub->p1->plane_y = -0.66;
}

void	fill_east(t_cub *cub)
{
	cub->p1->dir_x = 1;
	cub->p1->dir_y = 0;
	cub->p1->plane_x = 0;
	cub->p1->plane_y = 0.66;
}
void	init_player_dir(t_cub *cub)
{
	int x;
	int y;

	find_player(cub);
	x = cub->p1->pos_x;
	y = cub->p1->pos_y;
	if (!cub->p1 || x == -1 || y == -1)
		return ;
	if (cub->map[y][x] == 'N')
		fill_north(cub);
	else if (cub->map[y][x] == 'S')
		fill_south(cub);
	else if (cub->map[y][x] == 'W')
		fill_west(cub);
	else if (cub->map[y][x] == 'E')
		fill_east(cub);
	cub->map[y][x] = '0';
	cub->p1->pos_x += 0.5;
	cub->p1->pos_y += 0.5;
}
