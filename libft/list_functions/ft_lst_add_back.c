/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 01:50:22 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/17 18:17:56 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/* Adds the element ’new’ at the end of the list. If the list is empty, the   */
/* new node becomes the first element. If either argument is NULL, the        */
/* function does nothing.                                                     */
/* ************************************************************************** */
void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	last_node = NULL;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = ft_lst_last(*lst);
		last_node->next = new;
	}
}
