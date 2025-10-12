/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:46:38 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/11 19:46:38 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                             FT_HAS_DUPLICATES                              */
/*                                                                            */
/*   Checks if the stack contains any duplicate numbers.                      */
/*   Returns:                                                                 */
/*      1 -> duplicate found                                                  */
/*      0 -> no duplicates                                                    */
/* ************************************************************************** */
static int	ft_has_duplicates(t_stack *a)
{
	t_node_stack	*temp;
	t_node_stack	*compare_temp;

	temp = a->top;
	while (temp)
	{
		compare_temp = temp->next;
		while (compare_temp)
		{
			if (temp->number == compare_temp->number)
				return (1);
			compare_temp = compare_temp->next;
		}
		temp = temp->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                        FT_CHECK_INT_RANGE                                  */
/*                                                                            */
/*   Checks if the number fits within the integer range.                      */
/*   Returns:                                                                 */
/*      1 -> valid integer number                                             */
/*      0 -> invalid (out of int range)                                       */
/* ************************************************************************** */
static int	ft_check_int_range(long num)
{
	if (num > MAX_INT || num < MIN_INT)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                             FT_ERROR_EXIT                                  */
/*                                                                            */
/*   Frees the memory of stack A, writes "Error" to stderr, and exits the     */
/*   program.                                                                 */
/* ************************************************************************** */
static void	ft_error_exit(t_stack *a)
{
	ft_free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

/* ************************************************************************** */
/*                             FT_IS_NUMBER                                   */
/*                                                                            */
/*   Checks if the given string represents a valid integer number.            */
/*   Allows an optional '+' or '-' sign at the beginning, followed by         */
/*   one or more digits.                                                      */
/*   Returns:                                                                 */
/*      1 -> valid number                                                     */
/*      0 -> invalid number (contains non-digit characters or is empty)       */
/* ************************************************************************** */
static int	ft_is_number(char *string)
{
	int	index;

	index = 0;
	if (string[index] == '-' || string[index] == '+')
		index++;
	while (string[index])
	{
		if (!ft_is_digit(string[index]))
			return (0);
		index++;
	}
	return (1);
}

/* ************************************************************************** */
/*                             FT_PARSE_ARGS                                  */
/*                                                                            */
/*   Parses command-line arguments and validates them.                        */
/*   1 - FT_IS_NUMBER       : checks if the argument is digits or a sign      */
/*   2 - FT_CHECK_INT_RANGE : checks if the number fits in integer limits     */
/*   3 - FT_HAS_DUPLICATES  : checks if the stack contains duplicate numbers  */
/* ************************************************************************** */
void	ft_parse_args(int argc, char *argv[], t_stack *a)
{
	int		index;
	long	numb;

	index = 1;
	while (index < argc)
	{
		if (!ft_is_number(argv[index]))
			ft_error_exit(a);
		numb = ft_atol(argv[index]);
		if (!ft_check_int_range(numb))
			ft_error_exit(a);
		ft_stack_add_back(a, (int)numb);
		index++;
	}
	if (ft_has_duplicates(a))
		ft_error_exit(a);
}
