#include "push_swap.h"

/*ara està super cutre, s'ha de millorar molt*/

void	push_back(t_stack *stackA, t_stack *stackB)
{
	int	max;
	int	wrong;
	t_piece	*piece;

	max = max_game_num(stackB);			//podria fer servir la llargada de stackB
	wrong = 0;
	piece = stackB->first;
	while (max >= 0)
	{
		while (piece->game_num != max && piece->next->game_num != max)
		{
			piece = piece->next;
			rotate(stackB, "rb\n");
			wrong++;
		}
		if (piece->game_num != max)
			swap(stackB, "sb\n");			//sb??
		else
			piece = piece->next;
		push(stackA, stackB, "pa\n");		//pb??
		if (in_the_bottom(stackB, max - 1, wrong))
		{
			while (wrong > 0 && piece->game_num != max )
			{
				rev_rotate(stackB, "rrb\n");
				piece = piece->prev;
				wrong--;
			}
		}
		max--;
	}
}

void	push_chunks(t_stack *stackA, t_stack *stackB, int i)
{
	int	j;
	int	pushed;
	t_piece	*piece;

	j = i;
	pushed = 0;
	piece = stackA->first;
	while (pushed < 5 && check_if_sorted(stackA) == 0)
	{
		while (piece->game_num < j || piece->game_num > i + 4)
		{
			piece = piece->next;
			rotate(stackA, "ra\n");
		}
		push(stackB, stackA, "pb\n");		//pb?
		if (i == 0 && stackB->first->next->game_num == 42)
		{
			free(stackB->first->next);
			stackB->first->next = NULL;
		}
		j++;
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
	{
		push_chunks(stackA, stackB, i * 5);
		i++;
	}
	push_back(stackB, stackA);
}
