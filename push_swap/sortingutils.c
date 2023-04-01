#include "push_swap.h"

/*comprova si està ordenada des del final, si les peces que hi ha són les últimes ordenades, retorna 1 si sí i 0 si no*/

int	check_if_sorted(t_piece *stack)
{
	t_piece	piece;
	int		expected;

	piece = last_piece(stack);
	len = stack->len - 1;
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
	t_piece	piece;

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
