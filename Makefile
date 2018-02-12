NAME=minishell
CC=gcc
CFLAGS=-Wall -Wextra -Werror
INCLUDES=-Iincludes/ -Ilibft/includes/
SRCDIR=srcs/
LIBDIR=libft/

LIB=$(addprefix $(LIBDIR), libft.a)
SRC=$(addprefix $(SRCDIR), \
		main.c)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(LIB):
	$(MAKE) -j8 -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@ $(LIB)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean
	$(MAKE)

.PHONY: re fclean clean all
