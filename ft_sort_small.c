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

void	ft_sort_five(t_list **a, t_list **b)
{
	int	size;
	int	min;
	int	pos_index;

	size = ft_lst_size(*a);
	while (size-- > 3)
		ft_pb(b, a, 1);
	ft_sort_three(a);
	if (get_value(*b, 0) < get_value(*b, 1))
		ft_sb(b, 1);
	ft_pa(a, b, 1);
	ft_pa(a, b, 1);
	min = ft_find_extreme(*a, 0);
	pos_index = ft_find_index(*a, min);
	if (pos_index <= ft_lst_size(*a) / 2)
		while (pos_index-- > 0)
			ft_ra(a, 1);
	else
	{
		pos_index = ft_lst_size(*a) - pos_index;
		while (pos_index-- > 0)
			ft_rra(a, 1);
	}	
}


void	ft_sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = get_value(*a, 0);
	second = get_value(*a, 1);
	third = get_value(*a, 2);
	if (first > second && first > third)
		ft_ra(a, 1);
	else if (second > first && second > third)
		ft_rra(a, 1);
	if (get_value(*a, 0) > get_value(*a, 1))
		ft_sa(a, 1);
}

void	ft_small_sort(int argc, t_list **a, t_list **b)
{
	int	num_elements;

	num_elements = argc - 1;
	if (num_elements == 2 && get_value(*a, 0) > get_value(*a, 1))
		ft_sa(a, 1);
	else if (num_elements == 3)
		ft_sort_three(a);
	else if (num_elements == 5)
		ft_sort_five(a, b);
}


