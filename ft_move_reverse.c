/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:49:58 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/06 22:49:58 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* 		Rotates stack A down by one position.		        */
/*   		The last element becomes the first one.                   */
/* ************************************************************************** */
void	ft_rra(t_list **a, int print)
{
	t_list	*last_node;
	t_list	*second_last_node;

	if (!a || !(*a) || !(*a)->next)
		return ;
	second_last_node = (*a);
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	last_node = second_last_node->next;
	last_node->next = (*a);
	(*a) = last_node;
	second_last_node->next = NULL;
	if (print)
		ft_printf(1, "rra\n");
}

/* ************************************************************************** */
/* 		Rotates stack B down by one position.		        */
/*   		The last element becomes the first one.                   */
/* ************************************************************************** */
void	ft_rrb(t_list **b, int print)
{
	t_list	*last_node;
	t_list	*second_last_node;

	if (!b || !(*b) || !(*b)->next)
		return ;
	second_last_node = (*b);
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	last_node = second_last_node->next;
	last_node->next = (*b);
	(*b) = last_node;
	second_last_node->next = NULL;
	if (print)
		ft_printf(1, "rrb\n");
}

/* ************************************************************************** */
/*  	Applies reverse rotate to stack A and B simultaneously 	        */
/* ************************************************************************** */
void	ft_rrr(t_list **a, t_list **b, int is_print)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (is_print)
		ft_printf(1, "rrr\n");
}
