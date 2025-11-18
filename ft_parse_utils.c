/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:39:10 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/17 21:39:10 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*       			 MEMORY UTILS           		        */
/* ************************************************************************** */

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	cleanup(t_list **stack)
{
	if (stack && *stack)
		ft_lst_clear(stack, free);
}

/* ************************************************************************** */
/* Checks whether a value already exists in the stack to prevent duplicates.  */
/* ************************************************************************** */
int	check_duplicates(t_list *stack, int num)
{
	while (stack)
	{
		if (*(int *)stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/* ************************************************************************** */
/* Simple string-to-long conversion used for range checking before storing.   */
/* No undefined behavior: ignores leading spaces, handles optional sign.      */
/* ************************************************************************** */
long	local_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/* ************************************************************************** */
/* Verifies the string is a valid 32-bit integer representation. Checks sign, */
/* digit-only content, digit count and numeric range. Returns 1 if valid,     */
/* 0 otherwise.                                                               */
/* ************************************************************************** */
int	is_valid_number(char *str)
{
	long	num;
	int		i;
	int		digit_count;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	digit_count = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		digit_count++;
		i++;
	}
	if (digit_count > 10)
		return (0);
	num = local_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
