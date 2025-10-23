/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:45:52 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/23 15:45:52 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                              FT_SWAP_SA                                    */
/*                                                                            */
/*  Swaps the first 2 elements at the top of stack a.                         */
/*  Does nothing if there is only one or no elements.                         */
/* ************************************************************************** */
void	ft_swap_sa(t_stack **stack_a, int print)
{
	t_node_stack	*first;
	t_node_stack	*second;

	if (!stack_a || !*stack_a)
		return;
	if (!(*stack_a)->top || !(*stack_a)->top->next)
		return;
	first = (*stack_a)->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*stack_a)->top = second;
	if (print)
		ft_printf("sa\n");
}

/* ************************************************************************** */
/*                              FT_SWAP_SB                                    */
/*                                                                            */
/*  Swaps the first 2 elements at the top of stack b.                         */
/*  Does nothing if there is only one or no elements.                         */
/* ************************************************************************** */
void	ft_swap_sb(t_stack **stack_b, int print)
{
	t_node_stack	*first;
	t_node_stack	*second;

	if (!stack_b || !*stack_b)
		return;
	if (!(*stack_b)->top || !(*stack_b)->top->next)
		return;
	first = (*stack_b)->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*stack_b)->top = second;
	if (print)
		ft_printf("sb\n");
}

/* ************************************************************************** */
/*                              FT_SWAP_SS                                    */
/*                                                                            */
/*  Swaps the first 2 elements at the top of stack a and b.                   */
/*  Does nothing if there is only one or no elements.                         */
/* ************************************************************************** */
void	ft_swap_ss(t_stack **stack_a, t_stack **stack_b )
{
	if (stack_a && *stack_a && (*stack_a)->top && (*stack_a)->top->next)
		ft_swap_sa(stack_a, 0);
	if (stack_b && *stack_b && (*stack_b)->top && (*stack_b)->top->next)
		ft_swap_sb(stack_b, 0);
	ft_printf("ss\n");
}
