# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 19:36:15 by mnoguera          #+#    #+#              #
#    Updated: 2022/10/10 17:24:57 by mnoguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCS = ft_printf.c ft_putdecimal.c ft_puthexaupp.c ft_putvoidptr.c ft_puthexalow.c ft_putunsigdecimal.c

OBJS = $(SRCS:.c=.c)
HEADER = libft.h

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	make -C ./libft
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
