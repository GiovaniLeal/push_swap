/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:39:30 by marvin            #+#    #+#             */
/*   Updated: 2025/10/11 19:39:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                             FT_INIT_STACK                                  */
/*                                                                            */
/*   Initializes a stack structure and allocates memory using malloc.         */
/*   Returns:                                                                 */
/*      pointer to the newly created stack                                    */
/*      NULL if malloc fails                                                  */
/* ************************************************************************** */
static t_stack	*ft_init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->size = 0;
	new_stack->top = NULL;
	return (new_stack);
}

/* ************************************************************************** */
/*                                 MAIN                                       */
/*                                                                            */
/*   1 - FT_PARSE_ARGS : Checks if the arguments are valid. If valid, stores  */
/*      the numbers in stack A. If not, prints an error message and exits.    */
/*                                                                            */
/* ************************************************************************** */
int	main(int argc, char *argv[])
{
	t_stack	*a_stack;

	if (argc < 2)
		return (0);
	a_stack = ft_init_stack();
	if (!a_stack)
		return (1);
	ft_parse_args(argc, argv, a_stack);
	return (0);
}
