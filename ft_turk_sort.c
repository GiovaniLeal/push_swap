/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:41:18 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/29 20:41:18 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                             FT_SORT_THREE_CORE.C                           */
/* 						                  */
/* Sort exactly three elements in stack A using swap and rotate operations.   */
/* Handles all 5 possible orders of three indices and applies minimal moves. */
/* ************************************************************************** */

static void	ft_sort_three_core(t_stack **a, int top, int mid, int bot)
{
	if (top > mid && mid < bot && top < bot)
		ft_swap_sa(a, 1);                 // Case: 2 1 3 -> swap top two
	else if (top > mid && mid > bot)
	{
		ft_swap_sa(a, 1);                 // Case: 3 2 1 -> swap top two
		ft_reverse_rotate_a(a, 1);        // and rotate down
	}
	else if (top > mid && mid < bot && top > bot)
		ft_rotate_ra(a, 1);               // Case: 3 1 2 -> rotate up
	else if (top < mid && mid > bot && top < bot)
	{
		ft_swap_sa(a, 1);                 // Case: 1 3 2 -> swap top two
		ft_rotate_ra(a, 1);               // and rotate up
	}
	else if (top < mid && mid > bot && top > bot)
		ft_reverse_rotate_a(a, 1);        // Case: 2 3 1 -> rotate down
}

/* ************************************************************************** */
/*                             FT_SORT_THREE.C                                */
/* 						                  */
/* Sort stack A with 2 or 3 elements safely.                                  */
/* For 2 elements, swap if needed.                                           */
/* For 3 elements, delegate to ft_sort_three_core.                           */
/* ************************************************************************** */

void	ft_sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	if ((*a)->size < 2)
		return ;
	if ((*a)->size == 2)
	{
		top = (*a)->top->index;
		mid = (*a)->top->next->index;
		if (top > mid)
			ft_swap_sa(a, 1);
		return ;
	}
	top = (*a)->top->index;
	mid = (*a)->top->next->index;
	bot = (*a)->top->next->next->index;
	ft_sort_three_core(a, top, mid, bot);
}

/* ************************************************************************** */
/* 			     ft_turk_sort	                            */
/* 						                  */
/* Main sorting algorithm for stack A using Turk Sort strategy.               */
/* Sorts small stacks directly, pushes others to B, and reinserts efficiently.*/
/* Rotates A to position smallest element on top at the end.                  */
/* ************************************************************************** */

void	ft_turk_sort(t_stack **a_stack, t_stack **b_stack)
{
	int	size;

	size = (*a_stack)->size;
	if (size <= 3)
		ft_sort_three(a_stack);
	else
	{
		// Push all but three elements to B
		// Sort the three elements in A
		// While B is not empty
			// Move elements back to A with minimal rotations
		// Rotate A to put smallest element on top
	}
}
