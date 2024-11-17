NAME	=	libftprintf.a

SRCS	=	ft_printf_src.c

OBJS = $(SRCS:.c=.o)

CC	=	cc
RM	=	rm -f
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re