/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:29 by mnoguera          #+#    #+#             */
/*   Updated: 2022/12/08 16:25:21 by mnoguera         ###   ########.fr       */
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
int	getdata(int argc, char **argv, t_stack stackA);
int	is_int(char *number);
int	check_limit(char *num, int len);
int	fill_stack(t_stack stackA, int *data, int len);
int	game_number(int num, int *data, int len);

/*libft.c*/
int	ft_isdigit(int c);
int	ft_strlen(char *str);
int	ft_strncmp(const char *s1, const char *s2, int n);
int	ft_atoi(const char *str);

/*pieces.c*/
t_piece	*first_piece(void);
t_piece	*last_piece(t_piece *piece);
int	add_piece(t_piece *last, int number, int game_number);
void	free_pieces(t_piece **first);

#endif
