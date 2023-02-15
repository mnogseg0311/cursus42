/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:05:23 by mnoguera          #+#    #+#             */
/*   Updated: 2023/02/15 13:14:19 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_len(t_piece *piece)
{
	int	i;

	if (piece == NULL)
		return (0);
	i = 1;
	while (piece->next != NULL)
	{
		piece = piece->next;
		i++;
	}
	return (i);
}
