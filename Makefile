# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 19:39:44 by giodos-s          #+#    #+#              #
#    Updated: 2025/11/17 19:37:18 by giodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  CONFIGS                                     #
# **************************************************************************** #
NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INCLUDE = -I include -I libft/include
RM      = rm -f

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS =	main.c \
        ft_parse_and_init_stack.c \
        ft_parse_utils.c \
        ft_move_reverse.c \
        ft_move_rotate.c \
        ft_move_push_and_swap.c \
        ft_sort_small.c \
        ft_sort_utils.c \
        ft_turk_sort.c \
        ft_turk_utils.c \

OBJ     = $(SRCS:.c=.o)
LIBFT   = libft/libft.a

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[1;32m✅ Compilado com sucesso: $(NAME)\033[0m"

%.o: %.c $(wildcard include/*.h)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@$(MAKE) --no-print-directory -C libft
	@echo "\033[1;36m📚 Libft compilada!\033[0m"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) --no-print-directory -C libft clean
	@echo "\033[1;33m🧹 Objetos removidos.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C libft fclean
	@echo "\033[1;31m🗑️  Binário removido.\033[0m"

re: fclean all

.PHONY: all clean fclean re

