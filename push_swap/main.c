/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:30:35 by mnoguera          #+#    #+#             */
/*   Updated: 2023/03/21 17:45:56 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*imprieix les peces d'un stack, s'ha d'esborrar*/

void	print_pieces(t_stack *stackA)
{
	printf("\nPrint pieces:\n");
	t_piece	*piece;

	if (stackA->first == NULL)
		printf("stackA->first == NULL\n");

	piece = stackA->first;

	while (piece != NULL)
	{
		printf("num=%d\ngame_num=%d", piece->num, piece->game_num);
		if (piece->prev)
			printf("\nprev's num=%d", piece->prev->num);
		else
			printf("\n!piece->prev");
		printf("\n\n");
		piece = piece->next;
	}
}

/*s'hauria d'alliberar peça per peça, no?*/

static int print_error(t_stack	*stackA, t_stack *stackB)
{
	if (stackA)
		free(stackA);
	if (stackB)
		free(stackB);
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	if (argc == 1)
		return (1);
	stackA = malloc(sizeof(t_stack *));
	if (!stackA)
		return (print_error(stackA, stackB));
	stackA->first = getinput(argc, argv);
	if (!stackA->first)
		return (print_error(stackA, stackB));
	stackA->len = stack_len(stackA->first);
	stackB = malloc(sizeof(t_stack *));
	if (!stackB)
		return (print_error(stackA, stackB));
	stackB->first = new_piece();
	if (!stackA->first)
		return (print_error(stackA, stackB));
	stackB->first->game_num = 42;
	push_swap(stackA, stackB);

	print_pieces(stackA);

	free(stackA);
	free(stackB);
	return (0);
}