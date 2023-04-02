/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:11:34 by mnoguera          #+#    #+#             */
/*   Updated: 2023/03/21 17:56:49 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ordena dos elements*/

void	sort_two(t_stack *stack)
{
	if (stack->first->game_num > stack->first->next->game_num)
		swap(stack, "sa\n");
}

/*ordena tres elements*/

void	sort_three(t_stack *stack)
{
	if (last_piece(stack->first)->game_num == 1)
	{
		if (stack->first->game_num == 0)
			swap(stack, "sa\n");
		rotate(stack, "ra\n");
	}
	else
	{
		sort_two(stack);
		if (last_piece(stack->first)->game_num == 0)
			rev_rotate(stack, "rra\n");
	}
}

//quan l'input es "2 1 0", l'ordena correctament, pero en imprimir l'stack
//nomes s'imprimeixen les dos primeres peces, l'altra s'ha perdut???

/*separa els primers casos del general*/

void	push_swap(t_stack *stackA, t_stack *stackB)
{
	if (stackA->len == 1)
		return ;
	if (stackA->len == 2)
		sort_two(stackA);
	else if (stackA->len == 3)
		sort_three(stackA);
	else if (stackA->len > 3)
		sort_more(stackA, stackB);
}
