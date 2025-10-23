/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:15:27 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/23 19:15:27 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                              FT_ROTATE_RA                                  */
/*                                                                            */
/* ************************************************************************** */
void	ft_rotate_ra(t_stack **stack_a, int print)
{
	t_node_stack	*temp_node;
	t_node_stack	*last_node;

	if (!stack_a || !(*stack_a)->top)
		return;
	temp_node = (*stack_a)->top;
	(*stack_a)->top = temp_node->next;
	last_node = (*stack_a)->top;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = temp_node;
	temp_node->next = NULL;
	if (print)
		ft_printf("ra\n");
}

/* ************************************************************************** */
/*                              FT_ROTATE_RB                                  */
/*                                                                            */
/* ************************************************************************** */
void	ft_rotate_rb(t_stack **stack_b, int print)
{
	t_node_stack	*temp_node;
	t_node_stack	*last_node;

	if (!stack_b || !(*stack_b)->top)
		return;
	temp_node = (*stack_b)->top;
	(*stack_b)->top = temp_node->next;
	last_node = (*stack_b)->top;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = temp_node;
	temp_node->next = NULL;
	if (print)
		ft_printf("rb\n");
}

/* ************************************************************************** */
/*                              FT_ROTATE_RR                                  */
/*                                                                            */
/* ************************************************************************** */
void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return;
	ft_rotate_ra(stack_a, 0);
	ft_rotate_rb(stack_b, 0);
	ft_printf("rr\n");
}