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
	int				array_index;
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
				break ;
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
	current_node = (*stack_a)->top;
	while (i < array_size)
	{
		temp_array[i] = current_node->number;
		current_node = current_node->next;
		i++;
	}
	ft_bubble_sort(temp_array, array_size);
	ft_add_index_node(stack_a, temp_array);
	free(temp_array);
}
