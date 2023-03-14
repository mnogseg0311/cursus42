# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 17:17:08 by mnoguera          #+#    #+#              #
#    Updated: 2022/12/16 17:55:08 by mnoguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

#directories
SRCS_DIR = ./srcs
INCL_DIR = ./includes
OBJS_DIR = ./objs
LIBFT_DIR = ./libft

#source files
SRCS = $(SRCS_DIR)/*.c

#objects
OBJS = $(SRCS:.c=.o)

#library
HEADER = includes/push_swap.h

#libft
LIBFT = libft/libft.a

%.o : %.c $(LIBFT) Makefile
	$(CC) $(FLAGS) -c $< -o $@

obj:
	@mkdir $(OBJS_DIR)
	$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADER)
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
