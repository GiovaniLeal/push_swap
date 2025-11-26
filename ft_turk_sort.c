/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:31:50 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/20 18:45:16 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* 			FT_EXEC_BEST_MOVE			        */
/* ************************************************************************** */

static void	ft_exec_best_move(t_list **a, t_list **b, t_cost cost)
{
	while (cost.cost_a > 0 && cost.cost_b > 0)
	{
		ft_rr(a, b, 1);
		cost.cost_a--;
		cost.cost_b--;
	}
	while (cost.cost_a < 0 && cost.cost_b < 0)
	{
		ft_rrr(a, b, 1);
		cost.cost_a++;
		cost.cost_b++;
	}
	ft_move_stack(a, cost.cost_a, 'a');
	ft_move_stack(b, cost.cost_b, 'b');
	ft_pa(a, b, 1);
}

/* ************************************************************************** */
/* 			FT_MOVEMENT_OPTIMIZATION		        */
/* ************************************************************************** */

void	ft_movement_optimization(t_cost *current)
{
	int	is_simultaneous;

	if ((current->cost_a > 0 && current->cost_b > 0)
		|| (current->cost_a < 0 && current->cost_b < 0))
	{
		is_simultaneous = ft_min(ft_abs(current->cost_a),
				ft_abs(current->cost_b));
		current->total_cost -= is_simultaneous;
	}
}

/* ************************************************************************** */
/* 			FT_FIND_CHEAPEST_MOVE		        */
/* ************************************************************************** */

static void	ft_find_cheapest_move(t_list *a, t_list *b, t_cost *best_cost)
{
	int		index;
	int		first_element;
	t_list	*current;
	t_cost	current_cost;

	index = 0;
	current = b;
	first_element = 1;
	while (current)
	{
		ft_calculate_cost(a, b, &current_cost, index);
		ft_movement_optimization(&current_cost);
		if (first_element
			|| current_cost.total_cost < best_cost->total_cost)
		{
			*best_cost = current_cost;
			first_element = 0;
		}
		index++;
		current = current->next;
	}
}

/* ************************************************************************** */
/* 			FT_ROTATE_MIN_TOP			        */
/* ************************************************************************** */
void	ft_rotate_min_top(t_list **a)
{
	int	min_value;
	int	min_index;
	int	size;

	if (!a || !*a)
		return ;
	size = ft_lst_size(*a);
	min_value = ft_find_extreme(*a, 0);
	min_index = ft_find_index(*a, min_value);
	if (min_index <= size / 2)
		while (min_index-- > 0)
			ft_ra(a, 1);
	else
		while (min_index++ < size)
			ft_rra(a, 1);
}

/* ************************************************************************** */
/* 			FT_TURK_SORT		                  */
/* ************************************************************************** */
void	ft_turk_sort(t_list **a, t_list **b)
{
	int		size_stack_a;
	t_cost	best_cost;

	size_stack_a = ft_lst_size(*a);
	while (size_stack_a-- > 3)
		ft_pb(b, a, 1);
	ft_sort_three(a);
	while (*b)
	{
		best_cost.total_cost = INT_MAX;
		ft_find_cheapest_move(*a, *b, &best_cost);
		ft_exec_best_move(a, b, best_cost);
	}
	ft_rotate_min_top(a);
}
