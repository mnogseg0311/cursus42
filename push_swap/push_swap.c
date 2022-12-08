/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:47:29 by mnoguera          #+#    #+#             */
/*   Updated: 2022/12/08 16:25:17 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void	push_swap();

int	main(int argc, char **argv)
{
	t_stack	stackA;
	t_stack	stackB;

	if (argc == 1)
		return (1);
	if (checkinput(argv) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	
	stackB.first = NULL;
	stackB.len = 0;
}
