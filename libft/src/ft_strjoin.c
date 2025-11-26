/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:18:47 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/26 20:18:47 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** */
/*                             FT_STRJOIN                                     */
/*                                                                            */
/*   - Joins two strings into a new allocated string.                         */
/*   - Handles NULL inputs: treats NULL as empty string.                      */
/*   - Returns the newly allocated string, or NULL if allocation fails.       */
/* ************************************************************************** */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}
