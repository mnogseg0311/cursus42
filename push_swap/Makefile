# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 17:17:08 by mnoguera          #+#    #+#              #
#    Updated: 2023/03/15 14:12:36 by mnoguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

#directories
OBJS_DIR = ./objs
LIBFT_DIR = ./libft

#source files
SRCS = *.c

#objects
OBJS = $(SRCS:.c=.o)

#library
HEADER = push_swap.h

#libft
LIBFT = libft/libft.a

%.o : %.c $(LIBFT) Makefile
	$(CC) $(FLAGS) -c $< -o $@

obj:
	@mkdir $(OBJS_DIR)
	$(OBJS_DIR)%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: obj $(NAME)
	 all -C libft

$(NAME) : $(OBJS) $(HEADERS)
	ar -rsc $(NAME) $(OBJS)

clean:
	rm -Rf $(OBJS_DIR)
	clean -C libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
