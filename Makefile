# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahuanga <marvin@42fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 12:30:37 by ckulembe          #+#    #+#              #
#    Updated: 2026/02/13 07:33:26 by ahuanga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Variáveis para processo de compilação

CC	= gcc -g
CFLAGS 	= -Wall -Wextra -Werror
SRC_UTILS = utils/historic.c utils/handler_signal.c utils/view.c utils/vars.c utils/utils.c
SRC	= main.c $(SRC_UTILS) ft_validate_quotes.c  tokens/ft_tokenize.c tokens/utils_tokens.c\
	  tokens/ft_get_token_type.c parse/ft_check_syntax.c\
	  expansion/expansion.c expansion/utils.c expansion/expend.c
OBJS	= $(SRC:.c=.o)

#	Variáveis para nomeação simples

NAME	= minishell
TOKENS = tokens
# EXPANSION = expansion
PARSE = parse
LIB_DIR = libft
TOKEN_DIR = tokens
LIBFT	= $(LIB_DIR)/libft.a
RM	= rm -f

# INCLUDE = $()
#	Regras para a compilação do projeto e execução do projeto

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@make bonus -C $(LIB_DIR)
	$(CC) $(CFLAGS) -I$(LIB_DIR) -I$(TOKEN_DIR) -I$(PARSE) $(OBJS) -o $@ -L$(LIB_DIR) -lft -lreadline

%.o:%.c $(LIB_DIR)
	$(CC) $(CFLAGS) -I$(TOKEN_DIR) -c $< -o $@


#	Regras para destruição de arquivos .o e $(NAME)
#	incluindo os arquivos da libft...

clean:
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJS)

fclean:	clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME)

#	Reecompilação do projeto completo:
#	também reecompila o libft...

re: fclean all

.PHONY: all clean fclean re
