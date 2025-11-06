/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:02:11 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/04 12:02:11 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                CLEANUP                                     */
/*                                                                            */
/*   Frees allocated memory on error: content, list and temp array            */
/* ************************************************************************** */
static int	cleanup(int *content, int *temp, t_list **stack_a)
{
	if (content)
		free(content);
	if (stack_a && *stack_a)
		ft_lstclear(stack_a, free);
	if (temp)
		free(temp);
	return (0);
}

/* ************************************************************************** */
/*                               INIT_STACK_A                                 */
/*                                                                            */
/*   Parses arguments into integer array, creates linked list nodes.          */
/*   On error, frees all allocated memory and returns 0.                      */
/* ************************************************************************** */
int	init_stack_a(int num_args, char **args, t_list **stack_a)
{
	int		i;
	int		*temp;
	int		*content;
	t_list	*new;

	i = -1;
	temp = parse_args(num_args, args);
	if (!temp)
		return (0);
	while (++i < num_args)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (cleanup(NULL, temp, stack_a));
		*content = temp[i];
		new = ft_lstnew(content);
		if (!new)
			return (cleanup(content, temp, stack_a));
		ft_lstadd_back(stack_a, new);
	}
	free(temp);
	return (1);
}
