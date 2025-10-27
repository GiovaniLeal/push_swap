/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:23:40 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/27 11:23:40 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                         FT_REVERSE_ROTATE_RA                               */
/*                                                                            */
/*  Move all elements of stack A down by 1.The last element becomes the first.*/
/* ************************************************************************** */
void	ft_reverse_rotate_a(t_stack **a, int print)
{
	t_node_stack	*last_node;
	t_node_stack	*second_last_node;

	if (!a || !*a || !(*a)->top || !(*a)->top->next)
		return ;
	last_node = (*a)->top;
	second_last_node = NULL;
	while (last_node->next)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = (*a)->top;
	(*a)->top = last_node;
	if (print)
		ft_printf("rra\n");
}

/* ************************************************************************** */
/*                         FT_REVERSE_ROTATE_RB                               */
/*                                                                            */
/*  Move all elements of stack B down by 1.The last element becomes the first.*/
/* ************************************************************************** */
void	ft_reverse_rotate_b(t_stack **b, int print)
{
	t_node_stack	*last_node;
	t_node_stack	*second_last_node;

	if (!b || !*b || !(*b)->top || !(*b)->top->next)
		return ;
	last_node = (*b)->top;
	second_last_node = NULL;
	while (last_node->next)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = (*b)->top;
	(*b)->top = last_node;
	if (print)
		ft_printf("rrb\n");
}

/* ************************************************************************** */
/*                         FT_REVERSE_ROTATE_RRR                              */
/*                                                                            */
/*   rrr: reverse rotate both - Execute rra and rrb simultaneously.           */
/* ************************************************************************** */
void	ft_reverse_rotate_rrr(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	ft_reverse_rotate_a(a, 0);
	ft_reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}
