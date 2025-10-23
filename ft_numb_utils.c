/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numb_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 20:35:09 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/11 20:35:09 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                             FT_IS_DIGIT                                    */
/*                                                                            */
/*   Checks if the given character is a decimal digit ('0' to '9')            */
/*   according to the ASCII table.                                            */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_digit(char c)
{
	if  (c >= '0' && c <= '9' )
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                             FT_ATOL                                        */
/*                                                                            */
/*   Converts a numeric string to a long integer.                             */
/*   Handles an optional leading '+' or '-' sign.                             */
/*   !! Does not skip spaces or other non-digit characters. !!                */
/* ************************************************************************** */
long	ft_atol(char *str_arg)
{
	int	sign;
	int	index_numb;
	long	convert_number;

	sign = 1;
	index_numb = 0;
	convert_number = 0;

	if (str_arg[index_numb] == '-' || str_arg[index_numb] == '+')
	{
		if (str_arg[index_numb] == '-')
			sign = -1;
		index_numb++;
	}
	while (ft_is_digit(str_arg[index_numb]))
	{
		convert_number = convert_number * 10 +(str_arg[index_numb - '0']);
		index_numb++;
	}
	return (convert_number * sign);
}

