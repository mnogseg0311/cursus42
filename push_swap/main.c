/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:30:35 by mnoguera          #+#    #+#             */
/*   Updated: 2023/03/16 18:54:07 by mnoguera         ###   ########.fr       */
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
		printf("num=%d\ngame_num=%d\n\n", piece->num, piece->game_num);
		piece = piece->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	if (argc == 1)
		return (1);
	stackA = malloc(sizeof(t_stack *));
	stackA->first = getinput(argc, argv);
	if (stackA->first == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stackA->len = stack_len(stackA->first);
	stackB = malloc(sizeof(t_stack *));
		
	return (0);
}
