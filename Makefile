# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 19:39:44 by giodos-s          #+#    #+#              #
#    Updated: 2025/11/03 19:39:44 by giodos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PUSH_SWAP                                  #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -I include -I libft/includes

RM		= rm -f
RUNLIB	= -C libft

SRCSDIR	= srcs
OBJDIR	= objs

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS = main.c

# Adiciona o prefixo do diretório aos arquivos .c
SRCS := $(addprefix $(SRCSDIR)/, $(SRCS))

# Cria os caminhos dos .o dentro de objs/
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

# Biblioteca libft
LIBFT = libft/libft.a

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[1;32m✅ Compilado com sucesso: $(NAME)\033[0m"

# Compila os .c em objs/
$(OBJDIR)/%.o: $(SRCSDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;34mCompilando:\033[0m $<"

# Cria a pasta objs se não existir
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compila a libft
$(LIBFT):
	@$(MAKE) $(RUNLIB)
	@echo "\033[1;36m📚 Libft compilada!\033[0m"

# Limpeza
clean:
	@$(RM) -r $(OBJDIR)
	@$(MAKE) clean $(RUNLIB)
	@echo "\033[1;33m🧹 Objetos removidos.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean $(RUNLIB)
	@echo "\033[1;31m🗑️  Binário removido.\033[0m"

re: fclean all

.PHONY: all clean fclean re
