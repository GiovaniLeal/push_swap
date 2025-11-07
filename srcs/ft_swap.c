/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:31:12 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/06 23:31:12 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* swap_a: Swaps the first two elements at the top of stack A */
/* ************************************************************************** */

void	ft_sa(t_list **a, int print)
{
	int	temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	if (!print)
		return ;
	ft_printf("sa\n");
}

/* ************************************************************************** */
/* swap_b: Swaps the first two elements at the top of stack B */
/* ************************************************************************** */

void	ft_sb(t_list **b, int print)
{
	int	temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
	if (!print)
		return ;
	ft_printf("sb\n");
}

/* ************************************************************************** */
/* swap_both: Performs sa and sb simultaneously */
/* ************************************************************************** */

void	ft_ss(t_list **a, t_list **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	ft_printf("ss\n");
}
