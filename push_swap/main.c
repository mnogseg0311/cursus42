/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:30:35 by mnoguera          #+#    #+#             */
/*   Updated: 2022/12/15 18:33:27 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	print_pieces(t_stack stackA)
{
	t_piece	*piece;
	t_piece	*aux;

	piece = stackA.first;
	aux = piece;
	while (piece->next != NULL)
	{
		printf("num=%d\ngame_num=%d\n\n", aux->num, aux->game_num);
		aux = piece;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stackA;
	t_stack	stackB;

	if (argc == 1)
		return (1);
	stackB.first = NULL;
	stackB.len = 0;
	stackA.first = first_piece();
	stackA.len = 0;
	if (!getdata(argc, argv, &stackA))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	
	if (stackA.first->next == NULL)
		printf("\nnext es NULL\n\n");
	else
		printf("\nnext no es NULL\n\n");

//	print_pieces(stackA);
//el problema esta a getdata, modifica el next pero no num i game_num
	printf("primera peça: num=%d, game_num=%d\n", stackA.first->num, stackA.first->game_num);
	printf("StackA len = %d\n", stackA.len);
	return (0);
}

