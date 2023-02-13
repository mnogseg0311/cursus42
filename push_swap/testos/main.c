/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:30:35 by mnoguera          #+#    #+#             */
/*   Updated: 2022/12/16 18:05:33 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	print_pieces(t_stack *stackA)
{
	printf("\nEntra a print pieces\n");
	
	t_piece	*piece;

	if (stackA->first == NULL)
		printf("stackA->first == NULL\n");
	
	piece = stackA->first;
	
	if (piece == NULL)
		printf("piece == NULL\n");
	
	while (piece != NULL)
	{
		printf("num=%d\ngame_num=%d\n\n", piece->num, piece->game_num);
		piece = piece->next;
	}
	
	printf("final print pieces\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;

	printf("al main\n");
	if (argc == 1)
		return (1);
	
	printf("abans de get data\n");

	stackA = malloc(sizeof(stackA));

	stackA = getdata(argc, argv);
	
	printf("despres de get data\n");
	
	print_pieces(stackA);
	
	printf("stackA.len = %d\n", stackA->len);

	return (0);
}
