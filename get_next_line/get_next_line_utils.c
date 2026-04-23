/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:55:28 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/09 14:02:32 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_gnl(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_strcpy_gnl(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	join = (char *)malloc(len1 + len2 + 1);
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
	{
		ft_strcpy_gnl(join, s1);
		free(s1);
	}
	else
		join[0] = '\0';
	ft_strcpy_gnl(join + len1, s2);
	return (join);
}
