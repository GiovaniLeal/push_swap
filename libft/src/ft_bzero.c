/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:57:47 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/16 21:39:03 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** */
/*                               FT_BZERO                                     */
/*                                                                            */
/*   Erases data in the first `n` bytes of the memory area pointed to by `s`, */
/*  by setting all bytes to zero.                                             */
/*                                                                            */
/* ************************************************************************** */
void	ft_bzero(void *s, size_t n)
{
	size_t			*word_ptr;
	unsigned char	*byte_ptr;

	if (n == 0)
		return ;
	word_ptr = (size_t *)s;
	while (n >= sizeof(size_t))
	{
		*word_ptr = 0;
		n -= sizeof(size_t);
	}
	byte_ptr = (unsigned char *)word_ptr;
	while (n--)
		*byte_ptr++ = 0;
}
