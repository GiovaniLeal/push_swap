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
RUNLIB  = -C libft
OBJDIR  = objs


# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS =	main.c \
	ft_parse_and_init_stack_a.c \
	

OBJ		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIBFT		= libft/libft.a
# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[1;32m✅ Compilado com sucesso: $(NAME)\033[0m"

$(OBJDIR)/%.o: %.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;34mCompilando:\033[0m $<"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@$(MAKE) $(RUNLIB)
	@echo "\033[1;36m📚 Libft compilada!\033[0m"
clean:
	@$(RM) -r $(OBJDIR)
	@$(MAKE) $(RUNLIB) clean
	@echo "\033[1;33m🧹 Objetos removidos.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) $(RUNLIB) fclean
	@echo "\033[1;31m🗑️  Binário removido.\033[0m"

re: fclean all

.PHONY: all clean fclean re