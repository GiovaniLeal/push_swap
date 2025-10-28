/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_index_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:24:52 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/28 11:24:52 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ************************************************************************** */
/*                          fft_add_index_node                                */
/* ************************************************************************** */
void	ft_add_index_node(t_stack **stack_a, int *temp_array)
{
	int			array_index;
	t_node_stack	*current_node;

	current_node = (*stack_a)->top;
	while (current_node)
	{
		array_index = 0;
		while (array_index < (*stack_a)->size)
		{
			if (current_node->number == temp_array[array_index])
			{
				current_node->index = array_index;
				break;
			}
			array_index++;
		}
		current_node = current_node->next;
	}
}

/* ************************************************************************** */
/*                          ft_sort_temp_array                                */
/* ************************************************************************** */
int	ft_sort_temp_array(int *array, int start, int end)
{
	int	pivot;
	int	aux;

	pivot = (array[start] + array[end] + array[(start + end) / 2]) / 3;
	while (start < end)
	{
		while (start < end && array[start] <= pivot)
			start++;
		while (start < end && array[end] >= pivot)
			end --;
		aux = array[start];
		array[start] = array[end];
		array[end] = aux;
	}
	return (start);
}

/* ************************************************************************** */
/*                          FT_BUBBLE_SORT                                    */
/* ************************************************************************** */
void	ft_bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                          FT_PRINT_ARRAY_TEST                               */
/* ************************************************************************** */
void	ft_print_array_test(int *array, int size, char *message)
{
	int	i;

	ft_printf("%s: ", message);
	i = 0;
	while (i < size)
	{
		ft_printf("[%d]", array[i]);
		if (i < size - 1)
			ft_printf(" → ");
		i++;
	}
	ft_printf("\n");
}

/* ************************************************************************** */
/*                          FT_PRINT_STACK_INDICES                            */
/* ************************************************************************** */
void	ft_print_stack_indices(t_stack *stack, char *message)
{
	t_node_stack	*current;

	ft_printf("%s\n", message);
	ft_printf("Stack size: %d\n", stack->size);
	current = stack->top;
	while (current)
	{
		ft_printf("Value: %d → Index: %d\n", current->number, current->index);
		current = current->next;
	}
	ft_printf("---\n");
}

/* ************************************************************************** */
/*                          ft_put_index_node                                 */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
void	ft_put_index_node(t_stack **stack_a)
{
	int				i;
	int				array_size;
	int				*temp_array;
	t_node_stack	*current_node;

	i = 0;
	array_size = (*stack_a)->size;
	temp_array = malloc(sizeof(int) * array_size);
	if (!temp_array)
		return ;
	
	// 1. Preencher array
	current_node = (*stack_a)->top;
	while (i < array_size)
	{
		temp_array[i] = current_node->number;
		current_node = current_node->next;
		i++;
	}
	
	// TESTE: Mostrar array ANTES da ordenação
	ft_print_array_test(temp_array, array_size, "Array ANTES da ordenação");
	
	// 2. Ordenar array
	ft_bubble_sort(temp_array, array_size);
	
	// TESTE: Mostrar array DEPOIS da ordenação
	ft_print_array_test(temp_array, array_size, "Array DEPOIS da ordenação");
	
	// 3. Atribuir índices
	ft_add_index_node(stack_a, temp_array);
	
	// TESTE: Mostrar stack com índices
	ft_print_stack_indices(*stack_a, "Stack com índices atribuídos");
	
	free(temp_array);
}


