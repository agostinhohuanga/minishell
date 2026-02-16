DIR_BIN = bin

LIBFT   = -L../libft -lft
CC      = gcc -g
CFLAGS  = -Wall -Wextra -Werror -I../libft -I.

NAME_ECHO = $(DIR_BIN)/echo
RM = rm -f

SRC_ECHO = echo/main.c
OBJ_ECHO = $(SRC_ECHO:.c=.o)

HEADERS = built_in.h


all: $(NAME_ECHO)

$(DIR_BIN):
	mkdir -p $(DIR_BIN)

$(OBJ_ECHO): $(HEADERS)

$(NAME_ECHO): $(DIR_BIN) $(OBJ_ECHO)
	$(CC) $(CFLAGS) $(OBJ_ECHO) $(LIBFT) -o $(NAME_ECHO)

clean:
	$(RM) $(OBJ_ECHO)

fclean: clean
	rm -R $(DIR_BIN)

re: fclean all