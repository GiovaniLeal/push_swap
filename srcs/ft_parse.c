/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:28:36 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/04 13:28:36 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                             HAS_DUPLICATES                                 */
/*                                                                            */
/*   Checks for duplicate values in integer array. Returns 1 if duplicates    */
/*   are found, 0 otherwise.                                                  */
/* ************************************************************************** */
static int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                 FT_ATOL                                    */
/*                                                                            */
/*   Converts string to long, ignoring leading whitespace, handling sign.     */
/*   Returns 0 on invalid input.                                              */
/* ************************************************************************** */
static long	ft_atol(const char *str)
{
	int		sign;
	long	value;

	sign = 1;
	value = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		value = value * 10 + (*str++ - '0');
	return (value * sign);
}

/* ************************************************************************** */
/*                            IS_STR_DIGIT                                    */
/*                                                                            */
/*   Checks if string contains only digits and optional sign.                 */
/*   Returns 1 if valid, 0 otherwise.                                         */
/* ************************************************************************** */
static int	ft_isstrdigit(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return ;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                               PARSE_ARGS                                   */
/*                                                                            */
/*   Converts string arguments to integer array, validates digits,            */
/*   limits and duplicates. Returns NULL on error.                            */
/* ************************************************************************** */
int	*parse_args(int num_args, char **args)
{
	int		i;
	int		*temp;
	long	value;

	temp = malloc(sizeof(int) * (num_args - 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < num_args - 1)
	{
		if (!ft_isstrdigit(args[i + 1]))
			return (free(temp), NULL);
		value = ft_atol(args[i + 1]);
		if (value > INT_MAX || value < INT_MIN)
			return (free(temp), NULL);
		temp[i] = (int)value;
	}
	if (has_duplicates(temp, num_args - 1))
		return (free(temp), NULL);
	return (temp);
}
