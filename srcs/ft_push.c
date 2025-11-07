/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:51:02 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/06 21:51:02 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* 	Moves the first element from stack B to the top of stack A 	        */
/* ************************************************************************** */
void	ft_pa(t_list **a, t_list **b)
{
	t_list	*node_to_move;

	if (!b || !(*b))
		return ;
	node_to_move = *b;
	*b = (*b)->next;
	ft_lstadd_front_bonus(a, node_to_move);
	ft_printf("pa\n");
}

/* ************************************************************************** */
/* 	Moves the first element from stack B to the top of stack A 	        */
/* ************************************************************************** */
void	ft_pb(t_list **b, t_list **a)
{
	t_list	*node_to_move;

	if (!a || !(*a))
		return ;
	node_to_move = *a;
	*a = (*a)->next;
	ft_lstadd_front_bonus(b, node_to_move);
	ft_printf("pb\n");
}
