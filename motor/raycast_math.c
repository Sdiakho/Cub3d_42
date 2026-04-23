/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:20:36 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/20 14:41:16 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_cam_x(int witdh, double x)
{
	double res;

	res = ((2 * x) / witdh) - 1;
	return (res);
}

void	raycast(t_cub *cub, int width)
{
	int i;
	double cam_x;
	double ray_x;
	double ray_y;

	i = 0;
	while (i < width)
	{
		cam_x = get_cam_x(width, i);
		ray_x = cub->p1->dir_x + (cub->p1->plane_x * cam_x);
		ray_y = cub->p1->dir_y + (cub->p1->plane_y * cam_x);
		i++;
	}
}

dda(t_cub *cub, double ray_x, double ray_y)
{
	double deltaDX;
	double deltaDY;
	double stepX;
	double stepY;
	double sideY;
	double sideX;
	int map_x;
	int map_y;
	int hit;
	double less;

	map_x = (int)(cub->p1->pos_x);
	map_y = (int)(cub->p1->pos_y);
	if (ray_x != 0)
		deltaDX = fabs(1 / ray_x);
	else
		deltaDX = 1e30;
	if (ray_y != 0)
		deltaDY = fabs(1 / ray_y);
	else
		deltaDY = 1e30;
	if (ray_x >= 0)
	{
		stepX = 1;
		sideX = ((map_x + stepX) - (cub->p1->pos_x)) * deltaDX;
	}
	else
	{
		stepX = -1;
		sideX = (cub->p1->pos_x - map_x) * deltaDX;
	}
	if (ray_y >= 0)
	{
		stepY = 1;
		sideY = ((map_y + stepY) - cub->p1->pos_y) * deltaDY;
	}
	else
	{
		stepY = -1;
		sideY = (cub->p1->pos_y - map_y) * deltaDY;
	}
	while (hit == 0)
	{
		if (sideX < sideY)
		{
			map_x += stepX;
			sideX = deltaDX;
		}
		else
		{
			map_y += stepY;
			sideY = deltaDY;
		}
		if (cub->map[map_y][map_x] == '1')
			hit = 1;
	}
}
