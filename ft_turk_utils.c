/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodo-s@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:42:03 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/20 19:42:03 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* 			FT_FIND_POSITION_A			        */
/* Finds the target position in stack A for a given value. Returns the index  */
/* where the value should be inserted to maintain sorted order.               */
/* ************************************************************************** */
int	ft_find_position_a(t_list *a, int value)
{
	int		position;
	int		min;
	int		max;
	t_list	*current;

	if (!a)
		return (0);
	current = a;
	position = 0;
	min = ft_find_extreme(a, 0);
	max = ft_find_extreme(a, 1);
	if (value < min || value > max)
		return (ft_find_index(a, min));
	while (current)
	{
		if (current->next && value > *(int *)current->content
			&& value < *(int *)current->next->content)
			return (position + 1);
		if (!current->next && value > *(int *)current->content
			&& value < (*(int *)a->content))
			return (0);
		position++;
		current = current->next;
	}
	return (0);
}

/* ************************************************************************** */
/* 			FT_CALCULATE_COST			        */
/* Calculates rotation costs for moving elements between stacks.Determines    */
/* most efficient rotation direction for both stacks.                         */
/* ************************************************************************** */

void	ft_calculate_cost(t_list *a, t_list *b, t_cost *cost, int index_b)
{
	int	value;
	int	size_a;
	int	size_b;
	int	position_a;

	size_a = ft_lst_size(a);
	size_b = ft_lst_size(b);
	value = get_value(b, index_b);
	position_a = ft_find_position_a(a, value);
	if (position_a <= size_a / 2)
		cost->cost_a = position_a;
	else
		cost->cost_a = position_a - size_a;
	if (index_b <= size_b / 2)
		cost->cost_b = index_b;
	else
		cost->cost_b = index_b - size_b;
	cost->total_cost = ft_abs(cost->cost_a) + ft_abs(cost->cost_b);
	cost->value = value;
}

/* ************************************************************************** */
/* 			FT_MOVE_STACK			        */
/* Executes rotations on specified stack based on cost calculation. Positive  */
/* cost rotates forward, negative cost rotates backward.                      */
/* ************************************************************************** */

void	ft_move_stack(t_list **stack, int cost, char name)
{
	while (cost > 0)
	{
		if (name == 'a')
			ft_ra(stack, 1);
		else
			ft_rb(stack, 1);
		cost--;
	}
	while (cost < 0)
	{
		if (name == 'a')
			ft_rra(stack, 1);
		else
			ft_rrb(stack, 1);
		cost++;
	}
}
