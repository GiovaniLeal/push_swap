/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_init_stack_a.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:02:11 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/17 20:38:21 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* Processes a single numeric string, validating it, checking for duplicates, */
/* allocating space for the value and creating a new node. On success, the    */
/* number is appended to the stack. On failure, no changes are made.          */
/* Returns 1 on success, 0 on any validation or allocation error.             */
/* ************************************************************************** */
static int	handle_numbers(char *str, t_list **stack)
{
	long	temp;
	int		*value;
	t_list	*node;

	if (!is_valid_number(str))
		return (0);
	temp = local_atol(str);
	if (temp < INT_MIN || temp > INT_MAX)
		return (0);
	if (check_duplicates(*stack, (int)temp))
		return (0);
	value = malloc(sizeof(int));
	if (!value)
		return (0);
	*value = (int)temp;
	node = ft_lst_new(value);
	if (!node)
	{
		free(value);
		return (0);
	}
	ft_lsta_dd_back(stack, node);
	return (1);
}

/* ************************************************************************** */
/* Processes all arguments individually (argv[1] to argv[argc - 1]).          */
/* If any number is invalid, duplicated, or allocation fails, the entire      */
/* stack is cleared to avoid partial initialization.                          */
/* Returns 1 on success, or 0 if an error occurs.                             */
/* ************************************************************************** */
static int	process_multiple_args(int argc, char **argv, t_list **stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!handle_numbers(argv[i], stack))
		{
			cleanup(stack);
			return (0);
		}
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/* Splits a single argument such as "1 2 3" into multiple numbers and handles */
/* them individually. If an error occurs at any point, the allocated split    */
/* array is freed and the entire stack is cleared.                            */
/* Returns 1 on success, or 0 if an error or invalid number is encountered.   */
/* ************************************************************************** */
static int	process_single_argument(char *arg, t_list **stack)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	while (split[i])
	{
		if (!handle_numbers(split[i], stack))
		{
			free_split(split);
			cleanup(stack);
			return (0);
		}
		i++;
	}
	free_split(split);
	return (1);
}

/* ************************************************************************** */
/* Decides whether the input should be treated as a single space-separated    */
/* string (e.g., "./push_swap '1 2 3'") or as multiple arguments              */
/* ("./push_swap 1 2 3"). Delegates processing to the appropriate helper.     */
/* Returns 1 on success or 0 if input is invalid or processing fails.         */
/* ************************************************************************** */
int	ft_parse_and_init_stack(int argc, char **argv, t_list **stack)
{
	if (argc == 2 && ft_strchr(argv[1], ' '))
		return (process_single_argument(argv[1], stack));
	return (process_multiple_args(argc, argv, stack));
}

