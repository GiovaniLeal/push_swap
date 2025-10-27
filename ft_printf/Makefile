# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 12:08:35 by giodos-s          #+#    #+#              #
#    Updated: 2025/09/13 12:08:35 by giodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f
NAME    = libftprintf.a

# Mandatory sources
SRC     = ft_printf.c \
          ft_libft_utils.c \
          ft_list_utils.c \
          ft_node_utils.c \
          ft_numb_utils.c

# Bonus sources
SRC_BONUS = ft_printf_bonus.c \
            ft_dispatcher_bonus.c \
            ft_apply_flags_bonus.c \
            ft_apply_precision_bonus.c \
            ft_apply_width_bonus.c \
            ft_utils_bonus.c \
            ft_libft_utils.c \
            ft_list_utils.c \
            ft_node_utils.c \
            ft_numb_utils.c \
            ft_parse_format_bonus.c \
            ft_put_str_bonus.c

OBJ     = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
INCLUDES = -Iincludes -Ift_printf/includes -I.

# **************************************************************************** #
#                                RULES                                         #
# **************************************************************************** #

all: $(NAME)

# Compile mandatory objects and create lib
$(NAME): mandatory

mandatory: $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Compile bonus, overwrite lib
bonus: clean
	$(CC) $(CFLAGS) -c $(SRC_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)

# Generic compilation rule
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


