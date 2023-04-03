#include "push_swap.h"

/*comprova si està ordenada des del final, si les peces que hi ha són les últimes ordenades, retorna 1 si sí i 0 si no*/

int	check_if_sorted(t_stack *stack)
{
	t_piece	*piece;
	int		expected;
	
	piece = last_piece(stack->first);
	expected = stack->len - 1;
	while (piece->prev != NULL)
	{
		if (piece->game_num != expected)
			return (0);
		expected--;
		piece = piece->prev;
	}
	return (1);
}

int	max_game_num(t_stack *stack)
{
	int	max;
	t_piece	*piece;

	piece = stack->first;
	max = 0;
	while (piece->next != NULL)
	{
		if (piece->game_num > max)
			max = piece->game_num;
		piece = piece->next;
	}
	return (max);
}

/*1 si és un dels que havíem passat al final de l'stack, 0 si no, què passa si n'hi ha menys de 5???*/

int	in_the_bottom(t_stack *stack, int max, int wrong)
{
	//ha de mirar si és un dels que hem passat
	t_piece	*piece;
	int		i;

	piece = stack->first;
	i = 0;
	while (i <= 4 - wrong)
	{
		if (piece->game_num == max)
			return (0);
		piece = piece->next;
		i++;
	}
	return (1);
}