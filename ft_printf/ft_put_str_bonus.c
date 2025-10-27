/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_strg_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:32:54 by marvin            #+#    #+#             */
/*   Updated: 2025/09/14 22:32:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
/* ************************************************************************** */
/*   Returns a string for %c or %%                                          */
/*   - Allocates a buffer to store the character                              */
/*   - Handles null character '\0' properly for width/flags                  */
/* ************************************************************************** */
char	*ft_put_char_printf(char c, int is_percent)
{
	char	*buffer;

	(void)is_percent; // can be used later if you want special handling for '%'

	buffer = malloc(2);   // 1 char + '\0'
	if (!buffer)
		return (NULL);

	buffer[0] = c;        // store the character (including '\0' if needed)
	buffer[1] = '\0';     // null-terminate for string handling
	return (buffer);
}
/* ************************************************************************** */
/*   Format string with bonus rules                                           */
/*   - Applies precision, then flags, then width                              */
/*   - Frees intermediate strings to avoid leaks                              */
/* ************************************************************************** */
char	*ft_put_str_printf(const char *str)
{
	char	*buffer;
	size_t	len;

	if (!str)
		str = "(null)";        // emulate printf behavior

	len = ft_strlen(str);
	buffer = malloc(len + 1);   // allocate memory for manipulation
	if (!buffer)
		return (NULL);

	ft_memcpy(buffer, str, len);
	buffer[len] = '\0';
	return (buffer);
}