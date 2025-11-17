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

int	main(int argc, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!ft_parse_and_init_stack_a(stack_a))
		return (ft_printf("Error\n"));
	if (ft_is_ordered(&stack_a))
	{
		ft_lst_clear(&stack_a, free);
		return (0);
	}
	if (argc - 1 <= 3)
		ft_small_sort();
	else
		ft_turk_short();
	ft_lst_clear(&stack_a, free);
	ft_lst_clear(&stack_b, free);
	return (0);
}
