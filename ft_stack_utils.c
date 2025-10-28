/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 21:02:07 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/11 21:02:07 by giodos-s         ###   ########.fr       */
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
t_stack	*ft_init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new_stack->size = 0;
	new_stack->top = NULL;
	return (new_stack);
}

/* ************************************************************************** */
/*                           FT_INIT_NODE_STACK                               */
/*                                                                            */
/*   Creates a new stack node with the given number.                          */
/*   The index is set to -1 and next is initialized as NULL.                  */
/* ************************************************************************** */
t_node_stack	*ft_init_node_stack(int numb, t_stack *a)
{
	t_node_stack	*create_node;

	create_node = malloc(sizeof(t_node_stack));
	if (!create_node)
		ft_error_exit(a);
	create_node->number = numb;
	create_node->index = -1;
	create_node->next = NULL;
	return (create_node);
}

/* ************************************************************************** */
/*                           FT_STACK_ADD_BACK                                */
/*                                                                            */
/*   Adds a new node with the given number at the end of the stack.           */
/*   Uses ft_init_node_stack() to create the node.                            */
/* ************************************************************************** */
void	ft_stack_add_back(t_stack *a, int numb)
{
	t_node_stack	*add_node;
	t_node_stack	*temp;

	add_node = ft_init_node_stack(numb, a);
	if (!add_node)
		return ;
	if (!a->top)
	{
		a->top = add_node;
		a->size = 1;
		return ;
	}
	temp = a->top;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = add_node;
	a->size++;
}

/* ************************************************************************** */
/*                           FT_CLEAR_STACK                                   */
/*                                                                            */
/*   Frees all nodes in the stack and the stack structure itself.             */
/*   Behavior:                                                                */
/*      • Frees all nodes in the stack.                                       */
/*      • Frees the t_stack struct.                                           */
/*      • Sets the pointer to NULL to avoid dangling pointer.                 */
/* ************************************************************************** */
void	ft_free_stack(t_stack **a)
{
	t_node_stack	*next_node;
	t_node_stack	*cleaning_node;

	cleaning_node = (*a)->top;
	if (!a || !*a)
		return ;
	while (cleaning_node)
	{
		next_node = cleaning_node->next;
		free(cleaning_node);
		cleaning_node = next_node;
	}
	free(*a);
	*a = NULL;
}
