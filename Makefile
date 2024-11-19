# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emuzun <emuzun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 18:13:01 by emuzun            #+#    #+#              #
#    Updated: 2024/11/19 18:16:18 by emuzun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS  =  ft_printf_alph.c\
		ft_printf_num.c\
		ft_printf.c\

OBJS = $(SRCS:.c=.o)

CC	=	gcc
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
