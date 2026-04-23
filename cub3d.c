/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:31:40 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/23 15:53:39 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_cub	cub;
	t_list	*tmp;

	if (ac != 2)
		return (1);
	if (!check_ext(av[1]))
		return (printf("Error : Wrong extention map name\n"), 1);
	if (!init_cub(&cub))
		return (printf("Error : Malloc\n"), 1);
	cub.list_map = create_list(av[1], &cub);
	if (!cub.list_map)
		return (free(cub.p1), printf("Error : Malloc\n"), 1);
	remove_bn_list(&cub);
	if (!fill_config(&cub))
		return (free_list(&cub.list_map), printf("Error : Invalid data\n"), 1);
	if (!fill_rgb(&cub))
		return (free_list(&cub.list_map), printf("Error : Invalid datas\n"), 1);
	tmp = cub.list_map;
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	if (!check_map(&cub))
		return (printf("Error : Malloc\n"), 1);
	tmp = cub.map_start;
	printf("\n");
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	init_player_dir(&cub);
	printf("\n palyer pos x = %f, y = %f\n", cub.p1->pos_x, cub.p1->pos_y);
	tmp = cub.map_start;
	printf("\n");
	int i;
	i = 0;
	while (cub.map[i])
	{
		printf("%s\n", cub.map[i]);
		i++;
	}
	printf("%d ceil color\n", cub.rgb_ceil);
	printf("%d ceil color\n", cub.rgb_floor);
	return (0);
}
