/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiakho <sdiakho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:59:40 by sdiakho           #+#    #+#             */
/*   Updated: 2026/04/23 14:41:50 by sdiakho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_split(char **words)
{
	int	i;

	i = 0;
	if (!words)
		return ;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	checkc(char c, char *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

static int	countwords(char *str, char *sep)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		while (checkc(*str, sep) && *str)
			str++;
		if (!checkc(*str, sep) && *str)
			count++;
		while (!checkc(*str, sep) && *str)
			str++;
	}
	return (count);
}

static char	*word(char *start, char *end)
{
	char	*word;
	char	*first;

	word = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (!word)
		return (NULL);
	first = word;
	while (start < end)
	{
		*word = *start;
		word++;
		start++;
	}
	*word = '\0';
	return (first);
}

char	**ft_split(char *str, char *sep)
{
	char	**words;
	char	*start;
	int		count;
	int		j;

	count = countwords(str, sep);
	words = ft_calloc((count + 1), sizeof(char *));
	if (!words)
		return (NULL);
	j = 0;
	while (j < count)
	{
		while (*str && checkc(*str, sep))
			str++;
		start = str;
		while (*str && !checkc(*str, sep))
			str++;
		words[j] = word(start, str);
		if (!words[j])
			return (free_split(words), NULL);
		j++;
	}
	words[j] = NULL;
	return (words);
}
