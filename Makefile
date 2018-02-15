NAME=minishell
CC=gcc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address
INCLUDES=-Iincludes/ -Ilibft/includes/
LIBDIR=libft/

LIB=$(addprefix $(LIBDIR), libft.a)
SRC=	srcs/main.c \
		srcs/init_shell.c \
		srcs/ft_getenv.c \
		srcs/findenv.c \
		srcs/ft_exit.c \
		srcs/ft_echo.c \
		srcs/ft_cd.c \
		srcs/ft_env.c \
		srcs/ft_setenv.c \
		srcs/ft_unsetenv.c \
		srcs/getpath.c \
		srcs/process_input.c \
		srcs/deltab.c \
		srcs/is_builtin.c \
		srcs/prompt.c
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
