/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:39:17 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/24 09:18:39 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;
    int     offset;

    offset = (y * mlx->line_len) + (x * (mlx->bpp / 8));
    dst = mlx->addr + offset;
    *(unsigned int *)dst = color;
}

static int	init_mlx(t_cub *cub)
{
	cub->game.mlx = mlx_init();
	if (!cub->game.mlx)
		return (0);
	cub->game.win = mlx_new_windows(cub->game.mlx, 1920, 1080, "Cub3d");
	if (!cub->game.win)
		return (0);
	return (1);
}

static int	init_img(t_cub *cub)
{
	cub->game.img = mlx_new_image(cub->game.mlx, 1920, 1080);
	if (!cub->game.img)
		return (0);
	cub->game.addr = mlx_get_data_addr(cub->game.img, &cub->game.bpp, 
			&cub->game.line_len, cub->game.endian);
	return (1);
}
