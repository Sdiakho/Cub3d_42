/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:14:11 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/22 19:19:57 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_max(t_cub *cub, int *height)
{
	t_list *tmp;
	int cur;
	int max = -1;
	
	tmp = cub->map_start;
	while (tmp != NULL)
	{
		cur = ft_strlen(tmp->line);
		if (tmp->line[0] != '\n')
			(*height)++;
		if (max < cur)
			max = cur;
		tmp = tmp->next;
	}
	return (max);
}

void	fill_empty_map(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = 'F';
		i++;
	}
	str[i] = '\0';
}


int init_map(t_cub *cub)
{
	int width;
	int height;
	int i;

	height = 0;
	width = find_max(cub, &height);
	cub->height = height;
	cub->width = width;
	i = 0;
	cub->map = ft_calloc(sizeof(char *), (height + 1));
	if (!cub->map)
		return (0);
	while (i < height)
	{
		cub->map[i] = malloc(sizeof(char) * width + 1);
		if (!cub->map[i])
			return (free_split(cub->map), 0);
		fill_empty_map(cub->map[i], width);
		i++;
	}
	cub->map[i] = NULL;
	return (1);
}

void	fill_map(t_cub *cub)
{
	t_list *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = cub->map_start;
	while (tmp)
	{
		if (ft_strlen(tmp->line) == 0 || tmp->line[0] == '\n')
		{
			tmp = tmp->next;
			continue ;
		}
		else
		{
			j = 0;
			while (tmp->line[j] && tmp->line[j] != '\n')
			{
				if (tmp->line[j] == ' ')
				{
					j++;
					continue ;
				}
				cub->map[i][j] = tmp->line[j];
				j++; 
			}
			i++;
			tmp = tmp->next;
		}
	}
}

int parse_map(t_cub *cub)
{
	if (!init_map(cub))
		return (0);
	fill_map(cub);
	return (1);
}
