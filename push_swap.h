/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:26:03 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/17 19:29:43 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*         Libraries used: [MALLOC] - [LIBFT] -[FT_PRINTF]                    */
/* ************************************************************************** */
# include <stdlib.h>
# include <limits.h>
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"

/* ************************************************************************** */
/*                           DATA STRUCTURES                                  */
/*                                                                            */
/*   t_list  - LIBFT linked list for stack values                             */
/*   t_cost  - Movement cost tracking for algorithm optimization              */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	value;
}	t_cost;

/* ************************************************************************** */
/*       			  FUNCTIONS      			        */
/* ************************************************************************** */
int		main(int argc, char **argv);
int		ft_parse_and_init_stack(int argc, char **argv, t_list **stack);

/* ************************************************** */
/*         	 PARSE UTILS                      */
/* ************************************************** */
int		is_valid_number(char *str);
int		check_duplicates(t_list *stack, int num);
void	ft_free_split(char **split);
void	cleanup(t_list **stack);
long	local_atol(const char *str);

/* ************************************************** */
/*         	      MOVES                       */
/* ************************************************** */
void	ft_rra(t_list **a, int print);
void	ft_rrb(t_list **b, int print);
void	ft_rrr(t_list **a, t_list **b, int is_print);
void	ft_ra(t_list **a, int print);
void	ft_rb(t_list **b, int print);
void	ft_rr(t_list **a, t_list **b, int is_print);
void	ft_pa(t_list **a, t_list **b, int is_print);
void	ft_pb(t_list **b, t_list **a, int is_print);
void	ft_sa(t_list **a, int print);
void	ft_sb(t_list **b, int print);

/* ************************************************** */
/*                   SORT FUNCTION                    */
/* ************************************************** */
int		ft_is_ordered(t_list **stack);
void	ft_small_sort(int argc, t_list **a);
void	ft_sort_three(t_list **a);
void	ft_sort_five(t_list **a, t_list **b);
void	ft_turk_sort(t_list **a, t_list **b);
void	ft_movement_optimization(t_cost *current);
int		ft_find_position_a(t_list *a, int value);
void	ft_calculate_cost(t_list *a, t_list *b, t_cost *cost, int index_b);
void	ft_rotate_min_top(t_list **a);
void	ft_move_stack(t_list **stack, int cost, char name);

/* ************************************************** */
/*                     SORT UTILS                     */
/* ************************************************** */
int		get_value(t_list *lst, int index);
int		ft_find_extreme(t_list *lst, int find_max);
int		ft_find_index(t_list *lst, int value);
int		ft_abs(int n);
int		ft_min(int a, int b);

#endif