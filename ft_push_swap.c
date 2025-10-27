/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:39:30 by marvin            #+#    #+#             */
/*   Updated: 2025/10/11 19:39:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                             FT_IS_SORTED                                   */
/*                                                                            */
/*   This function checks if the stack 'a' is already sorted in ascending     */
/*   order.                                                                   */
/*   Returns:                                                                 */
/*      1 - if the stack is sorted                                            */
/*      0 - if the stack is not sorted                                        */
/* ************************************************************************** */
int	ft_is_sorted(t_stack *a_stack)
{
	t_node_stack	*temp_node;

	if (!a_stack || !a_stack->top)
		return (1);
	temp_node = a_stack->top;
	while (temp_node->next)
	{
		if (temp_node->number > temp_node->next->number)
			return (0);
		temp_node = temp_node->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                 MAIN                                       */
/*                                                                            */
/*   1 - FT_PARSE_ARGS : Checks if the arguments are valid. If valid, stores  */
/*      the numbers in stack A. If not, prints an error message and exits.    */
/*                                                                            */
/* ************************************************************************** */
int	main(int argc, char *argv[])
{
	t_stack	*a_stack;

	if (argc < 2)
		return (0);
	a_stack = ft_init_stack();
	if (!a_stack)
		return (1);
	ft_parse_args(argc, argv, a_stack);
	if (!ft_is_sorted(a_stack))
	{
		if (a_stack->size <= 3)
			ft_sort_three(a_stack);
		if (a_stack->size <= 5)
			ft_sort_five(a_stack);
		else
			ft_radix_sort(a_stack);
	}
	ft_clear_stack(&a_stack);
	return (0);
}
