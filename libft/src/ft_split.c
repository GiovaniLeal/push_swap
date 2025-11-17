/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:51:26 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/16 22:23:09 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**handle_empty_sep(const char *s)
{
	char	**array;

	array = malloc(sizeof(char *) * 2);
	if (!array)
		return (NULL);
	if (s[0] == '\0')
		array[0] = NULL;
	else
	{
		array[0] = ft_strdup(s);
		if (!array[0])
			return (free(array), NULL);
	}
	array[1] = NULL;
	return (array);
}

static size_t	count_substrings(const char *s, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != sep && (i == 0 || s[i - 1] == sep))
			count++;
		i++;
	}
	return (count);
}

static void	free_substrings(char **array, int last)
{
	while (last >= 0)
		free(array[last--]);
	free(array);
}

static char	**extract_substrings(char **array, const char *s, char sep)
{
	size_t	i;
	size_t	idx;
	size_t	start;

	i = 0;
	idx = 0;
	while (s[i])
	{
		if (s[i] != sep && (i == 0 || s[i - 1] == sep))
			start = i;
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
		{
			array[idx] = ft_substr(s, start, i - start + 1);
			if (!array[idx])
				return (free_substrings(array, idx - 1), NULL);
			idx++;
		}
		i++;
	}
	array[idx] = NULL;
	return (array);
}

/* ************************************************************************** */
/*                                   FT_SPLIT                                 */
/*                                                                            */
/*   Divide a string 's' em substrings usando 'sep' como delimitador.         */
/*   Retorna um array NULL-terminado contendo cada substring alocada.         */
/*   Em caso de falha de alocação, libera toda memória já alocada.            */
/*                                                                            */
/* ************************************************************************** */
char	**ft_split(const char *s, char sep)
{
	char	**array;
	size_t	total_substrings;

	if (!s)
		return (NULL);
	if (sep == '\0')
		return (handle_empty_sep(s));
	total_substrings = count_substrings(s, sep);
	array = malloc((total_substrings + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (extract_substrings(array, s, sep));
}
