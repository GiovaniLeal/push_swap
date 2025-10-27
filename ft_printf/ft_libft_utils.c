/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:41:21 by giodos-s          #+#    #+#             */
/*   Updated: 2025/09/11 19:41:21 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ************************************************************************** */
/* STRING FUNCTIONS - CHAR AND STRING HANDLERS                                */
/* ************************************************************************** */
char	*ft_put_char_generic(char c)
{
	char	*buffer;

	buffer = malloc(2);
	if (!buffer)
		return (NULL);
	buffer[0] = c;
	buffer[1] = '\0';
	return (buffer);
}

/* ************************************************************************** */
/*  Generic string handler                                                    */
/* - Returns an allocated copy of the string if do_alloc = 1                  */
/* - Handles NULL strings                                                     */
/* - Does NOT apply precision; it will be handled separately (bonus)         */
/* ************************************************************************** */
char	*ft_put_str_generic(const char *str, int do_alloc)
{
	size_t	len;
	char	*buffer;

	if (!str)
		str = "(null)";
	if (!do_alloc)
		return (ft_strdup(str));
	len = ft_strlen(str);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, str, len);
	buffer[len] = '\0';
	return (buffer);
}

/* ************************************************************************** */
/* STRING LENGTH FUNCTION - RETURNS LENGTH OF STRING                          */
/* ************************************************************************** */
int	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (6);
	while (str[count])
		count++;
	return ((int)count);
}

/* ************************************************************************** */
/* STRING DUPLICATE - ALLOCATES NEW COPY OF STRING                            */
/* ************************************************************************** */
char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*buffer;

	len = ft_strlen(str);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, str, len);
	buffer[len] = '\0';
	return (buffer);
}

/* ************************************************************************** */
/* MEMORY COPY FUNCTION - COPIES N BYTES FROM SRC TO DEST                     */
/* ************************************************************************** */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_bytes;
	const unsigned char	*src_bytes;

	if (!dest && !src && n > 0)
		return (NULL);
	dest_bytes = (unsigned char *)dest;
	src_bytes = (const unsigned char *)src;
	while (n-- > 0)
	{
		*dest_bytes = *src_bytes;
		dest_bytes++;
		src_bytes++;
	}
	return (dest);
}
