/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:29:05 by mnoguera          #+#    #+#             */
/*   Updated: 2023/02/16 19:17:29 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa o sb _____ al write posar  la llargada
void	swap(t_stack *stack, char *name)
{
	t_piece	*aux;

	aux = stack->first->next;
	stack->first->next = aux->next;
	aux->next = stack->first;
	stack->first = aux;
	write(1, name, 5);
}

void rotate(t_stack *stack, char *name)
{
	t_piece	*aux;

	aux = last_piece(stack->first);
	aux->next = stack->first;
	aux = stack->first->next;
	stack->first->next = NULL;
	stack->first = aux;
	write(1, name, 5);
}

void rev_rotate(t_stack *stack, char *name)
{
	t_piece	*aux;

	aux = last_piece(stack->first);
	aux->next = stack->first;
	stack->first = aux;
	//falta que l'anterior a l'aux apunti a NULL
	write(1, name, 5);
}
