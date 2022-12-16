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
	t_piece	*piece;

	piece = stackA->first;
	while (piece != NULL)
	{
		printf("num=%d\ngame_num=%d\n\n", piece->num, piece->game_num);
		piece = piece->next;
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
	stackA.first = NULL;
	stackA.len = 0;
	if (!getdata(argc, argv, &stackA))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	print_pieces(&stackA);							//no peta, pero no fa res
	printf("stackA.len = %d\n", stackA.len);		//es 0 sempre, no afegeix peces
	return (0);
}

