# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giodos-s <giodo-s@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 18:51:52 by giodos-s          #+#    #+#              #
#    Updated: 2025/11/17 18:51:52 by giodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               CONFIGURAÇÕES                                  #
# **************************************************************************** #

NAME		= libft.a
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

# **************************************************************************** #
#                               ARQUIVOS FONTE                                 #
# **************************************************************************** #

# Libft - Funções essenciais
LIBFT_SRC	= 		ft_atoi.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_isdigit.c \
			  ft_memcpy.c \
			  ft_split.c \
			  ft_strchr.c \
			  ft_strdup.c \
			  ft_strlen.c \
			  ft_substr.c \
			  ft_strjoin.c

# Libft - Funções de lista
LIST_SRC	= ft_lst_add_back.c \
			ft_lst_add_front.c \
			  ft_lst_clear.c \
			  ft_lst_last.c \
			  ft_lst_new.c \
			  ft_lst_size.c

# Printf
PRINTF_SRC	= ft_printf.c \
			ft_libft_utils.c \
			ft_list_utils.c \
			ft_node_utils.c \
			ft_numb_utils.c \

GNL_SRC		= get_next_line.c \
			get_next_line_utils.c

# **************************************************************************** #
#                               PATHS COMPLETOS                                #
# **************************************************************************** #

SRC_DIR		= src
LIST_DIR		= list_functions
PRINTF_DIR	= printf
GNL_DIR		= gnl

SRC		= $(addprefix $(SRC_DIR)/, $(LIBFT_SRC)) \
			  $(addprefix $(LIST_DIR)/, $(LIST_SRC)) \
			  $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC)) \
			  $(addprefix $(GNL_DIR)/, $(GNL_SRC))

OBJ			= $(SRC:.c=.o)

# **************************************************************************** #
#                               REGRAS PRINCIPAIS                              #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "✅ $(NAME) criada com sucesso!"

%.o: %.c $(wildcard include/*.h)
	@$(CC) $(CFLAGS) -I./include -c $< -o $@

# **************************************************************************** #
#                               LIMPEZA                                        #
# **************************************************************************** #

clean:
	@$(RM) $(OBJ)
	@echo "🧹 Objetos da libft removidos"

fclean: clean
	@$(RM) $(NAME)
	@echo "🗑️  $(NAME) removida"

re: fclean all

# **************************************************************************** #
#                               UTILITÁRIOS                                    #
# **************************************************************************** #

norm:
	@norminette $(SRC_DIR) $(LIST_DIR) $(PRINTF_DIR) ./include

.PHONY: all clean fclean re norm