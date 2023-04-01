/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:29 by mnoguera          #+#    #+#             */
/*   Updated: 2023/03/21 17:17:01 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct s_piece
{
	int				num;
	int				game_num;
	struct s_piece	*prev;
	struct s_piece	*next;
}					t_piece;

typedef struct s_stack
{
	t_piece *first;
	int 	len;
} t_stack;

/*getdata.c*/
t_piece	*getinput(int argc, char **argv);
t_piece	*getdata(int len, char **str);
int		*game_numbers(int *data, int len);
t_piece	*get_list(int *data, int *game_nums, int len);
int		game_number(int num, int *data, int len);

/*datautils.c*/
int		count_nums(char *str);
int		is_int(char *number);
char	*trim_zeros(char *num);
int		check_limit(char *num, int len);

/*pieces.c*/
t_piece	*new_piece(void);
t_piece	*last_piece(t_piece *pce);
void	add_piece_back(t_piece **pce, t_piece *new);
void	add_piece_front(t_piece **pce, t_piece *new);
int		stack_len(t_piece *piece);

/*instructions.c*/
void	swap(t_stack *stack, char *name);
void	push(t_stack *one, t_stack *two, char *name);
void	rotate(t_stack *stack, char *name);
void	rev_rotate(t_stack *stack, char *name);
void	doubles(t_stack *stackA, t_stack *stackB, char *name, void (*instruction)(t_stack *, char *));

/*sorting.c*/
void	push_swap(t_stack *stackA, t_stack *stackB);
void	sort_two(t_stack *stackA);

//a esborrar (main.c)
void print_pieces(t_stack *stackA);
#endif
