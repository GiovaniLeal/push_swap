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
/*        Libraries used: [MALLOC] - [WRITE] - [FT_PRINTF]                    */
/* ************************************************************************** */
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

/* ************************************************************************** */
/*                                STRUCTS                                     */
/*                                                                            */
/*   t_stack       : Structure to control a stack.                            */
/*   t_node_stack  : Structure to control the numbers within the stack.       */
/*   Notes:                                                                   */
/*     - t_stack holds a pointer to the top node and the size of the stack.   */
/*     - t_node_stack holds the value (number) and a pointer to the next node.*/
/* ************************************************************************** */
typedef struct s_node_stack
{
	int					number;
	int					index;
	struct s_node_stack		*next;	
}	t_node_stack;

typedef struct s_stack
{
	int				size;
	t_node_stack	*top;
}	t_stack;

/* ************************************************************************** */
/* 			     FUNCTIONS 	                            */
/* ************************************************************************** */
int		main(int argc, char *argv[]);

/* *************************************************** */
/*               PUSH_SWAP.C                           */
/* *************************************************** */
int		ft_is_sorted(t_stack *a_stack);

/* *************************************************** */
/*               FT_STACK_UTILS.C                      */
/* *************************************************** */
t_stack	*ft_init_stack(void);
void	ft_free_stack(t_stack **a);
void	ft_stack_add_back(t_stack *a, int numb);
t_node_stack	*ft_init_node_stack(int numb, t_stack *a);

/* *************************************************** */
/*               FT_NUMB_UTILS.C                       */
/* *************************************************** */
int		ft_is_digit(char c);
long	ft_atol(char *str_arg);

/* *************************************************** */
/*               FT_CHECK_ERRORS.C                     */
/* *************************************************** */
void	ft_parse_args(int argc, char *argv[], t_stack *a);
void	ft_error_exit(t_stack *a);

/* *************************************************** */
/*               FT_PUSH_INDEX_NODE.C                  */
/* *************************************************** */
void	ft_add_index_node(t_stack **stack_a, int *temp_array);
int		ft_sort_temp_array(int *array, int start, int end);
void	ft_bubble_sort(int *array, int size);
void	ft_put_index_node(t_stack **stack_a);

void	ft_print_array_test(int *array, int size, char *message);
void	ft_print_stack_indices(t_stack *stack, char *message);

/* *************************************************** */
/*               FT_PUSH.C                             */
/* *************************************************** */
void	ft_push_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_push_pb(t_stack **stack_a, t_stack **stack_b);

/* *************************************************** */
/*               FT_REVERSE_ROTATE.C                   */
/* *************************************************** */
void	ft_reverse_rotate_a(t_stack **a, int print);
void	ft_reverse_rotate_b(t_stack **b, int print);
void	ft_reverse_rotate_rrr(t_stack **a, t_stack **b);

/* *************************************************** */
/*               FT_ROTATE.C                           */
/* *************************************************** */
void	ft_rotate_ra(t_stack **stack_a, int print);
void	ft_rotate_rb(t_stack **stack_b, int print);
void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b);

/* *************************************************** */
/*               FT_SWAP.C                             */
/* *************************************************** */
void	ft_swap_sa(t_stack **stack_a, int print);
void	ft_swap_sb(t_stack **stack_b, int print);
void	ft_swap_ss(t_stack **stack_a, t_stack **stack_b);

#endif