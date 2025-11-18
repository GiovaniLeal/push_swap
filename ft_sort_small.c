/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:42:59 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/17 22:36:39 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort(int argc, t_list **a)
{
	int	num_elements;

	num_elements = argc - 1;
	if (num_elements == 2 && get_value(*a) > get_value((*a)->next))
		ft_sa(a, 1);
	else if (num_elements == 3)
		ft_sort_three(a);
}

void	ft_sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = get_value(*a);
	second = get_value((*a)->next);
	third = get_value((*a)->next->next);
	if (first > second && first > third)
	{
		ft_ra(a, 1);
		if (get_value(*a) > get_value((*a)->next))
			ft_sa(a, 1);
	}
	else if (second > first && second > third)
	{
		ft_rra(a, 1);
		if (get_value(*a) > get_value((*a)->next))
			ft_sa(a, 1);
	}
	else if (get_value(*a) > get_value((*a)->next))
	{
		ft_sa(a, 1);
	}
}
