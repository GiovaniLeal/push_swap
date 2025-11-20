/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:48:11 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/17 22:48:11 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*  Returns the content value stored at a given index of a t_list node.       */
/* ************************************************************************** */

int	get_value(t_list *lst, int index)
{
	int	count;
	t_list	*current_node;

	if (!lst || index < 0)
		return (-1);
	i = 0;
	current_node = lst;
	while (current_node && count < index)
	{
		current = current->next;
		count++;
	}
	if (!current)
		return (-1);
	return (current->content);
}
