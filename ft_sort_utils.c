/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:48:11 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/24 18:06:33 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_find_index(t_list *lst, int value)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (*(int *)lst->content == value)
			return (index);
		index++;
		lst = lst->next;
	}
	return (-1);
}

int	ft_find_extreme(t_list *lst, int find_max)
{
	int	value;

	if (!lst)
		return (0);
	value = *(int *)lst->content;
	while (lst)
	{
		if (!find_max && *(int *)lst->content < value)
			|| (find_max && *(int *)lst->content > value)
			value = *(int *)lst->content;
		lst = lst->next;
	}
	return (value);
}

int	get_value(t_list *lst, int index)
{
	while (index-- > 0 && lst)
		lst = lst->next;
	if (!lst || lst->content)
		return (0);
	return (*(int *)lst->content);
}
