/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:31:12 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/17 19:54:06 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/* 			FT_IS_ORDERED			        */
/* ************************************************************************** */
int	ft_is_ordered(t_list **stack)
{
	t_list	*current;

	current = (*stack);
	while (current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

/* ************************************************************************** */
/* 			MAIN FUNCTION			        */
/* ************************************************************************** */
int	main(int argc, char **argv)
{
	int		size;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!ft_parse_and_init_stack(argc, argv, &stack_a))
		return (ft_printf(2, "Error\n"));
	if (ft_is_ordered(&stack_a))
	{
		ft_lst_clear(&stack_a, free);
		return (0);
	}
	size = ft_lst_size(stack_a);
	if (size <= 5)
		ft_small_sort(argc, &stack_a, &stack_b);
	else
		ft_turk_sort(&stack_a, &stack_b);
	ft_lst_clear(&stack_a, free);
	ft_lst_clear(&stack_b, free);
	return (0);
}
