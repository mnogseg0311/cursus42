/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:29 by mnoguera          #+#    #+#             */
/*   Updated: 2023/02/23 16:49:10 by mnoguera         ###   ########.fr       */
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
t_piece		*getinput(int argc, char **argv);
int		is_int(char *number);
int		check_limit(char *num, int len);
t_piece		*get_list(int *data, int len);
int		game_number(int num, int *data, int len);

/*libft.c*/
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_atoi(const char *str);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*pieces.c*/
t_piece	*last_piece(t_piece *pce);
void	add_piece_back(t_piece **pce, t_piece *new);
void	add_piece_front(t_piece **pce, t_piece *new);
int		stack_len(t_piece *piece);

/*instructions.c*/
void	swap(t_stack *stack, char *name);
void	rotate(t_stack *stack, char *name);
void	rev_rotate(t_stack *stack, char *name);

//a esborrar (main.c)
void print_pieces(t_stack *stackA);
#endif
