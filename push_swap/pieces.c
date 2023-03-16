/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:05:23 by mnoguera          #+#    #+#             */
/*   Updated: 2023/03/16 19:29:56 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*crea una nova peça i inicialitza tots els seus elements a 0*/

t_piece	*new_piece(void)
{
	t_piece	*new;

	new = malloc(sizeof(t_piece));
	new->num = 0;
	new->game_num = 0;
	new->next = NULL;
	return (new);
}

/*retorna l'ultima peça de l'stack*/

t_piece	*last_piece(t_piece *pce)
{
	if (pce == NULL)
		return (pce);
	while (pce->next != NULL)
		pce = pce->next;
	return (pce);
}

/*afegeix una peça al final de l'stack*/

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

/*afegeix una peça a l'inici de l'stack*/

void	add_piece_front(t_piece **pce, t_piece *new)
{
	new->next = *pce;
	*pce = new;
}

/*calcula la llargada d'un stack*/

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
