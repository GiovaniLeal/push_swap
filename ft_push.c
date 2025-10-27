/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:37:33 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/23 18:37:33 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                              FT_PUSH_PA                                    */
/*                                                                            */
/* 	    Pushes the top element from stack B to stack A                  */
/* ************************************************************************** */
void	ft_push_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_node_stack	*node_to_move;

	if (!stack_a || !stack_b || !(*stack_b)->top)
		return ;
	node_to_move = (*stack_b)->top;
	(*stack_b)->top = node_to_move->next;
	node_to_move->next = (*stack_a)->top;
	(*stack_a)->top = node_to_move;
	(*stack_a)->size++;
	(*stack_b)->size--;
	ft_printf("pa\n");
}

/* ************************************************************************** */
/*                              FT_PUSH_PB                                    */
/*                                                                            */
/* 	    Pushes the top element from stack A to stack B                  */
/* ************************************************************************** */
void	ft_push_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_node_stack	*node_to_move;

	if (!stack_b || !stack_a || !(*stack_a)->top)
		return ;
	node_to_move = (*stack_a)->top;
	(*stack_a)->top = node_to_move->next;
	node_to_move->next = (*stack_b)->top;
	(*stack_b)->top = node_to_move;
	(*stack_b)->size++;
	(*stack_a)->size--;
	ft_printf("pb\n");
}
