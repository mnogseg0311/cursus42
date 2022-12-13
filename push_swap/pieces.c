/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:37:30 by mnoguera          #+#    #+#             */
/*   Updated: 2022/12/13 16:09:01 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	free_pieces(t_piece **first)
{
	t_piece	*piece;

	if (!first)
		return ;
	piece = *first;
	while (*first)
	{
		piece = (*first)->next;
		free(first->num);
		free(first->game_num);
		free(first);
		*first = piece;
	}
}
*/
#include <stdio.h>
int	add_piece(t_piece *last, int number, int game_number)
{
	t_piece	*new;

	printf("a afegir una nova peça\n");
	new = malloc(sizeof(t_piece));
	if (!new)
		return (0);
	printf("number=%d, game_number=%d\n", number, game_number);
	new->num = number;
	new->game_num = game_number;
	new->next = NULL;
	printf("new->num=%d, new->game_num=%d\n", new->num, new->game_num);
	last->next = new;
	return (1);
}

t_piece	*last_piece(t_piece *piece)
{
	if (piece == NULL)
		return (NULL);
	while (piece->next != NULL)
		piece = piece->next;
	return (piece);
}

t_piece	*first_piece(void)
{
	t_piece *first;
	
	first = malloc(sizeof(t_piece));
	if (!first)
		return (NULL);
	first->num = 0;
	first->game_num = 0;
	first->next = NULL;
	return (first);
}
