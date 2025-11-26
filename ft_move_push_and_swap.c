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
void	ft_pa(t_list **a, t_list **b, int is_print)
{
	t_list	*node_to_move;

	if (!b || !(*b))
		return ;
	node_to_move = *b;
	*b = (*b)->next;
	ft_lst_add_front(a, node_to_move);
	if (is_print)
		ft_printf("pa\n");
}

/* ************************************************************************** */
/* 	Moves the first element from stack A to the top of stack B	        */
/* ************************************************************************** */
void	ft_pb(t_list **b, t_list **a, int is_print)
{
	t_list	*node_to_move;

	if (!a || !(*a))
		return ;
	node_to_move = *a;
	*a = (*a)->next;
	ft_lst_add_front(b, node_to_move);
	if (is_print)
		ft_printf("pb\n");
}

/* ************************************************************************** */
/* swap_a: Swaps the first two elements at the top of stack A */
/* ************************************************************************** */
void	ft_sa(t_list **a, int print)
{
	int		*temp;

	if (!a || !*a || !(*a)->next)
	{
		return ;
	}
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	if (print)
		ft_printf("sa\n");
}

/* ************************************************************************** */
/* swap_b: Swaps the first two elements at the top of stack B */
/* ************************************************************************** */
void	ft_sb(t_list **b, int print)
{
	int		*temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
	if (print)
		ft_printf("sb\n");
}
