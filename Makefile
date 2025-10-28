# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 15:27:06 by giodos-s          #+#    #+#              #
#    Updated: 2025/10/28 15:27:06 by giodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Source files - LISTE TODOS SEUS ARQUIVOS AQUI
SRCS		= 	ft_push_swap.c \
			  ft_stack_utils.c \
			  ft_numb_utils.c \
			  ft_check_errors.c \
			  ft_push_index_node.c \
			  ft_push.c \
			  ft_reverse_rotate.c \
			  ft_rotate.c \
			  ft_swap.c

# Object files directory
OBJS		= $(SRCS:.c=.o)

# Libft printf
PRINTF_DIR	= ft_printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(PRINTF_DIR) fclean

re: fclean all

# Phony targets
.PHONY: all clean fclean re