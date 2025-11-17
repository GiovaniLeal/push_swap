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
int	main(int argc, char **args);
#endif