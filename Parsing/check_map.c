/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:34:54 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/22 17:42:54 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_ext(char *str)
{
	int len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (ft_strncmp(&str[len - 4], ".cub", 4) == 0)
		return (1);
	return (0);
}

int verif_carac(char c)
{
	int		i;
	char	*valid;

	valid = "01NWSE ";
	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (1);
		i++;
	}
	return (0);
}

int is_pl_pos(char c)
{
	int		i;
	char	*valid;

	valid = "NWES";
	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (1);
		i++;
	}
	return (0);
}

int check_carac(t_cub *cub)
{
	int i;
	int		count_pl_pos;
	t_list *tmp;

	count_pl_pos = 0;
	tmp = cub->map_start;
	while (tmp)
	{
		i = 0;
		while(tmp->line[i] && tmp->line[i] != '\n')
		{
			if (!verif_carac(tmp->line[i]))
				return (0);
			if (is_pl_pos(tmp->line[i]))
				count_pl_pos++;
			i++;
		}
		tmp = tmp->next;
	}
	if (count_pl_pos != 1)
		return (0);
	return (1);
}

int check_map(t_cub *cub)
{
	int i;

	if (!check_carac(cub))
		return (0);
	if (!parse_map(cub))
		return (0);
	i = 0;
	if (!check_flood(cub))
		return (0);
	while (cub->map[i])
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
	restore_flood(cub);
	printf("\n");
	i = 0;
	while (cub->map[i])
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
	return (1);
}


// int main(int ac, char **av)
// {
// 	int i;
// 	int fd;
// 	char *path;
// 	t_cub cub;

// 	if (ac != 2)
// 		return (1);
// 	path = av[1];
// 	fd = open(path, O_RDONLY);
// 	if (fd < 1)
// 		return (1);
// 	cub.list_map = create_list(fd, &cub);

// 	close(fd);
// 	if (!cub.list_map)
// 		return (1);
// 	printf("%d\n", check_map(&cub));
// 	restore_flood(&cub);
// 	init_player_dir(&cub);
// 	printf("x = %f : y = %f, pos = %c\n", cub.p1->pos_x, cub.p1->pos_y, cub.map[(int)cub.p1->pos_y][(int)cub.p1->pos_x]);
// 	i = 0;
// 	while (cub.map[i])
// 	{
// 		printf("%s\n", cub.map[i]);
// 		i++;
// 	}
// 	free_list(&cub.list_map);
// 	return (0);
// }
