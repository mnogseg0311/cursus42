# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 19:36:15 by mnoguera          #+#    #+#              #
#    Updated: 2022/10/13 16:15:23 by mnoguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SRCS	= ft_printf.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putnbr.c\
	ft_puthexaupp.c\
	ft_putvoidptr.c\
	ft_puthexalow.c\
	ft_putunsigdecimal.c\
	ft_strlen.c\

OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
