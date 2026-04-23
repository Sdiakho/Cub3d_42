/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:55:25 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/09 14:02:18 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_free(char *s1)
{
	if (s1)
		free(s1);
	return (NULL);
}

char	*extract_line(const char *s1)
{
	int		end;
	int		len;
	char	*line;
	int		i;

	if (!s1)
		return (NULL);
	end = ft_strchr_gnl(s1);
	if (end == -1)
		len = ft_strlen_gnl(s1);
	else
		len = end + 1;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s1[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash_crop(char *s1)
{
	int		end;
	int		i;
	int		j;
	char	*new_stash;

	if (!s1)
		return (NULL);
	end = ft_strchr_gnl(s1);
	if (end == -1)
		return (ft_free(s1));
	i = end + 1;
	if (!s1[i])
		return (ft_free(s1));
	j = 0;
	while (s1[i + j])
		j++;
	new_stash = (char *)malloc(sizeof(char) * (j + 1));
	if (!new_stash)
		return (ft_free(s1));
	ft_strcpy_gnl(new_stash, &s1[i]);
	free(s1);
	return (new_stash);
}

char	*read_to_stash(int fd, char *stash, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (ft_strchr_gnl(stash) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 42);
		if (bytes_read < 0)
		{
			if (stash)
				free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin_gnl(stash, buffer);
		if (!tmp)
		{
			return (NULL);
		}
		stash = tmp;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (42 + 1));
	if (!buffer)
	{
		stash = ft_free(stash);
		return (NULL);
	}
	stash = read_to_stash(fd, stash, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		stash = ft_free(stash);
		return (NULL);
	}
	stash = clean_stash_crop(stash);
	return (line);
}
