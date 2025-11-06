/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:26:03 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/03 19:26:03 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*         Libraries used: [MALLOC] - [LIBFT] -[FT_PRINTF]                    */
/* ************************************************************************** */
# include <stdlib.h>
# include "../libft/includes/libft.h"

/* ************************************************************************** */
/*                                STRUCT                                      */
/* Nesse projeto criaremos apenas uma struct para armazenar o custo dos movi- */
/* mentos. Aproveitaremos a struct da LIBFT [T_LIST] para a criacao de uma 
lista linkada */
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
int	main(int argc, char **args);
int	init_stack_a(int num_args, char **args, t_list **stack_a);
int	*parse_args(int num_args, char **args);

#endif