/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:13:30 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/06 22:13:30 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* 		Rotates stack A upward by one position.		        */
/*   		The first element becomes the last one.                   */
/* ************************************************************************** */
void	ft_ra(t_list **a, int print)
{
	t_list	*node_to_move;

	if (!a || !(*a) || !(*a)->next)
		return ;
	node_to_move = (*a);
	*a = (*a)->next;
	node_to_move->next = NULL;
	ft_lst_add_back(a, node_to_move);
	if (print)
		ft_printf("ra\n");
}

/* ************************************************************************** */
/* 		Rotates stack B upward by one position.		        */
/*   		The first element becomes the last one.                   */
/* ************************************************************************** */
void	ft_rb(t_list **b, int print)
{
	t_list	*node_to_move;

	if (!b || !(*b) || !(*b)->next)
		return ;
	node_to_move = (*b);
	*b = (*b)->next;
	node_to_move->next = NULL;
	ft_lst_add_back(b, node_to_move);
	if (print)
		ft_printf("rb\n");
}

/* ************************************************************************** */
/*  		Rotates stack A and B simultaneously 		        */
/* ************************************************************************** */
void	ft_rr(t_list **a, t_list **b, int is_print)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (is_print)
		ft_printf("rr\n");
}
