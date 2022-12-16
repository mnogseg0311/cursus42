/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:05:23 by mnoguera          #+#    #+#             */
/*   Updated: 2022/12/16 16:39:37 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_piece	*new_piece(int num, int game_num)
{
	t_piece	*new;

	new = malloc(sizeof(t_piece));
	if (!new)
		return (NULL);
	new->num = num;
	new->game_num = game_num;
	new->next = NULL;
	return (new);
}

t_piece	*last_piece(t_piece *pce)
{
	if (pce == NULL)
		return (pce);
	while (pce->next != NULL)
		pce = pce->next;
	return (pce);
}

void	add_piece_back(t_piece **pce, t_piece *new)
{
	t_piece	*aux;

	if (pce && new)
	{
		if (!*pce)
		{
			*pce = new;
			return ;
		}
		aux = last_piece(*pce);
		aux->next = new;
	}
}

void	add_piece_front(t_piece **pce, t_piece *new)
{
	new->next = *pce;
	*pce = new;
}

int	add_piece(t_stack *stack, int num, int game_num)
{
	t_piece	*new;
	t_piece	*pce;

	pce = NULL;
	new = new_piece(num, game_num);
	if (!new)
		return (0);
	pce = last_piece(stack->first);
	add_piece_back(&pce, new);
	return (1);
}
