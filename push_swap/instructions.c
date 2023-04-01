/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:29:05 by mnoguera          #+#    #+#             */
/*   Updated: 2023/03/16 19:22:53 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*intercanvia els dos primers elements d'un stack*/

void	swap(t_stack *stack, char *name)
{
	t_piece	*aux;

	aux = stack->first->next;
	stack->first->next = aux->next;
	aux->next = stack->first;
	aux->next->prev = stack->first;
	stack->first->prev = aux;
	aux->prev = NULL;
	stack->first = aux;
	write(1, name, ft_strlen(name));
}

/*posa el primer element de l'stack two al principi de l'stack one*/

void	push(t_stack *one, t_stack *two, char *name)
{
	t_piece	*aux;

	if (!two)
		return ;
	aux = two->first;
	two->first = aux->next;
	two->first->prev = NULL;
	aux->next = one->first;
	one->first->prev = aux;
	aux->prev = NULL;
	one->first = aux;
	write(1, name, ft_strlen(name));
}

/*puja tots els elements de l'stack en un, el primer element passa a ser l'utim*/

void	rotate(t_stack *stack, char *name)
{
	t_piece	*aux;

	aux = last_piece(stack->first);
	aux->next = stack->first;
	stack->first->prev = aux;
	aux = stack->first->next;
	stack->first->next = NULL;
	aux->prev = NULL;
	stack->first = aux;
	write(1, name, ft_strlen(name));
}

/*baixa tots els elements de l'stack en un, l'ultim passa a ser el primer*/

void	rev_rotate(t_stack *stack, char *name)
{
	t_piece	*aux;

	aux = last_piece(stack->first);
	aux->next = stack->first;
	stack->first = aux;
	stack->first->prev = NULL;
	aux = aux->prev;
	aux->next = NULL;
	write(1, name, ft_strlen(name));
}

/*instruction es una de les funcions anteriors, name ss\n, rr\n o rrr\n*/

void	doubles(t_stack *stackA, t_stack *stackB, char *name, void (*instruction)(t_stack *, char *))
{
	instruction(stackA, "");
	instruction(stackB, "");
	write(1, name, ft_strlen(name));
}
