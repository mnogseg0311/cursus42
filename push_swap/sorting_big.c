#include "push_swap.h"

/*ara està super cutre, s'ha de millorar molt*/

void	push_back(t_stack *stackA, t_stack *stackB)
{
	int	max;
	int	wrong;
	t_piece	piece;

	max = max_game_num(stackB);
	wrong = 0;
	piece = stackB->first_piece;
	while (max >= 0)
	{
		while (piece->game_num != max)
		{
			piece = piece->next;
			rotate(stackB, "rb");
			wrong++;
		}
		push(stackA, stackB, "pa");		//pb??
		while (wrong > 0)
		{
			rev_rotate(stackB, "rrb");
			wrong--;
		}
		max--;
	}
}

void	push_chunks(t_stack *stackA, t_stack *stackB, int i)
{
	int	j;
	t_piece	piece;

	j = i;
	piece = stackA->first;
	while (j <= i + 4 && check_if_sorted(stackA) == 0)
	{
		while (piece->game_num != j)
			piece = piece->next;
		push(stackB, stackA, "pb");		//pb?
	}
}

void	sort_more(t_stack *stackA, t_stack *stackB)
{
	int	chunks;
	int	i;

	chunks = stackA->len / 5;
	if (stackA->len % 5 != 0)
		chunks++;
	i = 0;
	while (i <= chunks && check_if_sorted(stackA) == 0)
		push_chunks(stackA, stackB, i);
	push_back(stackB, stackA);
}
