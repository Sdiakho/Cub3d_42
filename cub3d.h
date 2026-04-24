/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:09:57 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/24 08:53:14 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;
			
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}			t_mlx;

typedef struct s_cub
{
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*ceil;
	char		*floor;
	t_player	p1;
	t_mlx		game;
	int			rgb_ceil;
	int			rgb_floor;
	int			height;
	int			width;
	t_list		*list_map;
	t_list		*map_start;
}			t_cub;


/*  Parsing  */
int		init_cub(t_cub *cub);
int		fill_rgb(t_cub *cub);
int		fill_config(t_cub *cub);
int		check_ext(char *str);
int		is_pl_pos(char c);
void	remove_bn(char *line);
void	remove_bn_list(t_cub *cub);
int		check_flood(t_cub *cub);
void	restore_flood(t_cub *cub);
int		find_max(t_cub *cub, int *height);
int		parse_map(t_cub *cub);
void	free_list(t_list **all);
int		check_map(t_cub *cub);
t_list	*create_list(char *path, t_cub *cub);

/*  motor  */
void	init_player_dir(t_cub *cub);


/*  Utils  */
int		ft_strlen(char *str);
void	free_split(char **split);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup(char *src);
char	**ft_split(char *str, char *sep);
void	free_split(char **words);
int		ft_atoi(const char *str, int *out);



/* GNL */
char	*ft_free(char *s1);
char	*get_next_line(int fd);
char	*clean_stash_crop(char *s1);
char	*extract_line(const char *s1);
int		ft_strchr_gnl(const char *str);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_strcpy_gnl(char *dest, const char *src);
char	*read_to_stash(int fd, char *stash, char *buffer);

#endif