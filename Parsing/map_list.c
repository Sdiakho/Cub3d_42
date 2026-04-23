/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:35:50 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/22 14:10:05 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_list	*create_node(char *line)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

void	add_back(t_list **all, t_list *new)
{
	t_list *tmp;

	if (!(*all))
	{
		*all = new;
		return ;
	}
	tmp = *all;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

void	free_list(t_list **all)
{
	t_list *tmp;

	tmp = *all;
	while (*all)
	{
		*all = (*all)->next;
		free(tmp->line);
		free(tmp);
		tmp = *all;
	}
	*all = NULL;
}

void	remove_bn_list(t_cub *cub)
{
	t_list	*tmp;

	tmp = cub->list_map;
	while (tmp)
	{
		remove_bn(tmp->line);
		tmp = tmp->next;
	}
	return ;
}

t_list	*create_list(char *path, t_cub *cub)
{
	char *line;
	t_list *all;
	t_list *new;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all = NULL;
	cub->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		new = create_node(line);
		if (!new)
			return (close(fd), free_list(&all), NULL);
		add_back(&all, new);
		line = get_next_line(fd);
	}
	close(fd);
	return (all);
}

// int main(void)
// {
// 	int fd;
// 	t_cub cub;

// 	fd = open("../maps/test.cub", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	cub.list_map = create_list(fd, &cub);
// 	while (cub.list_map)
// 	{
// 		printf("%s", cub.list_map->line);
// 		cub.list_map = cub.list_map->next;
// 	}
// 	free_list(&cub.list_map);
// 	return (0);
// }
