/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:43:34 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/22 17:54:42 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_cub(t_cub *cub)
{
	cub->ceil = NULL;
	cub->ea_path = NULL;
	cub->floor = NULL;
	cub->list_map = NULL;
	cub->map = NULL;
	cub->no_path = NULL;
	cub->so_path = NULL;
	cub->we_path = NULL;
	cub->rgb_ceil = -1;
	cub->rgb_floor = -1;
	cub->map_start = NULL;
	cub->p1 = malloc(sizeof(t_player));
	if (!cub->p1)
		return (0);
	cub->p1->pos_x = -1;
	cub->p1->pos_y = -1;
	return (1);
}

int	valid_struct(t_cub *cub)
{
	if (!cub->no_path || !cub->ea_path || !cub->we_path || !cub->so_path)
		return (0);
	if (!cub->ceil || !cub->floor)
		return (0);
	return (1);
}

int	is_map_line(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ')
			i++;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
int	dispatcher(char *line, t_cub *cub, int *config)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (1);
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		return ((*config)++, cub->no_path = ft_strdup(&line[i + 3]), 1);
	if (ft_strncmp(&line[i], "SO ", 3) == 0)
		return ((*config)++, cub->so_path = ft_strdup(&line[i + 3]), 1);
	if (ft_strncmp(&line[i], "WE ", 3) == 0)
		return ((*config)++, cub->we_path = ft_strdup(&line[i + 3]), 1);
	if (ft_strncmp(&line[i], "EA ", 3) == 0)
		return ((*config)++, cub->ea_path = ft_strdup(&line[i + 3]), 1);
	if (ft_strncmp(&line[i], "F ", 2) == 0)
		return ((*config)++, cub->floor = ft_strdup(&line[i + 2]), 1);
	if (ft_strncmp(&line[i], "C ", 2) == 0)
		return ((*config)++, cub->ceil = ft_strdup(&line[i + 2]), 1);
	else
		return (0);
}

int fill_config(t_cub *cub)
{
	int config;
	int i;
	t_list	*tmp;

	config = 0;
	tmp = cub->list_map;
	while (config != 6 && tmp)
	{
		if (!dispatcher(tmp->line, cub, &config))
			return (0);
		tmp = tmp->next;
		printf("%d\n", config);
	}
	if (valid_struct(cub))
	{
		i = 0;
		while (tmp && tmp->line[i] == '\n')
			tmp = tmp->next;
		cub->map_start = tmp;
		if (is_map_line(tmp->line))
			return (1);
		else
			return (0);
	}
	return (0);
}



// int main(int ac, char **av)
// {
// 	int fd;
// 	char *path;
// 	t_list *tmp;
// 	t_cub cub;

	
// 	if (ac != 2)
// 		return (1);
// 	path = av[1];
// 	fd = open(path, O_RDONLY);
// 	if (fd < 1)
// 		return (1);
// 	init_cub(&cub);
// 	cub.list_map = create_list(fd, &cub);
// 	close(fd);
// 	if (!cub.list_map)
// 		return (1);
// 	tmp = cub.list_map;
// 	remove_bn_list(&cub);
// 	if (!fill_config(&cub))
// 		return (printf("Error\n"), 1);
// 	else
// 	{
// 		free_list(&cub.list_map);
// 		return (0);
// 	}
// }
