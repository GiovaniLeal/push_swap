/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:13:41 by giodos-s          #+#    #+#             */
/*   Updated: 2025/10/11 19:13:41 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/* ************************************************************************** */
/*                   Libraries used: [MALLOC] - [WRITE]                       */
/* ************************************************************************** */
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                STRUCTS                                     */
/*                                                                            */
/*   t_stack       : Structure to control a stack.                            */
/*   t_node_stack  : Structure to control the numbers within the stack.       */
/*   Notes:                                                                   */
/*     - t_stack holds a pointer to the top node and the size of the stack.   */
/*     - t_node_stack holds the value (number) and a pointer to the next node.*/
/* ************************************************************************** */
typedef struct s_stack
{
	int				size;
	t_node_stack	*top;
}	t_stack;

typedef struct s_node_stack
{
	int					number;
	int					index;
	struct s_node_stack	*next;	
}	t_node_stack;

/* ************************************************************************** */
/* 			     FUNCTIONS 	                            */
/* ************************************************************************** */
int		main(int argc, char *argv[]);
void	ft_parse_args(int argc, char *argv[], t_stack *a);
void	ft_stack_add_back(t_stack *a, int numb);
#endif