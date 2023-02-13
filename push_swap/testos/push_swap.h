/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:29 by mnoguera          #+#    #+#             */
/*   Updated: 2022/12/16 17:56:06 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_piece
{
	int				num;
	int				game_num;
	struct s_piece	*next;
}					t_piece;

typedef struct s_stack
{
	t_piece *first;
	int 	len;
} t_stack;

/*getdata.c*/
t_stack		*getdata(int argc, char **argv);
int		is_int(char *number);
int		check_limit(char *num, int len);
t_stack		*fill_stack(int *data, int len);
int		game_number(int num, int *data, int len);

/*libft.c*/
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_atoi(const char *str);

/*pieces.c*/
t_piece	*new_piece(int num, int game_num);
t_piece	*last_piece(t_piece *pce);
void	add_piece_back(t_piece **pce, t_piece *new);
void	add_piece_front(t_piece **pce, t_piece *new);
t_stack		add_piece(t_stack *stack, int num, int game_num);

//a esborrar (main.c)
void print_pieces(t_stack *stackA);
#endif
