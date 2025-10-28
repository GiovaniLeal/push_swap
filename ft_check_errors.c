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
/*                             FT_HAS_DUPLICATE                               */
/*                                                                            */
/*   Checks if the stack already contains the given number.                   */
/*   Returns:                                                                 */
/*      1 -> duplicate found                                                  */
/*      0 -> no duplicate                                                     */
/* ************************************************************************** */
static int	ft_has_duplicate(t_stack *a, int num)
{
	t_node_stack	*temp;

	if (!a || !a->top)
		return (0);  // Stack vazia, não há duplicatas
	
	temp = a->top;
	while (temp)
	{
		if (temp->number == num)
			return (1);  // Encontrou duplicata
		temp = temp->next;
	}
	return (0);  // Não encontrou duplicata
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
void	ft_error_exit(t_stack *a)
{
	ft_free_stack(&a);
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
/*   3 - FT_HAS_DUPLICATE   : checks if the number is already in the stack    */
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
		
		// ✅ VERIFICA DUPLICATA ANTES de adicionar
		if (ft_has_duplicate(a, (int)numb))  // Precisará ajustar a função
			ft_error_exit(a);
		
		// ✅ AGORA adiciona na stack
		ft_stack_add_back(a, (int)numb);
		index++;
	}
}
