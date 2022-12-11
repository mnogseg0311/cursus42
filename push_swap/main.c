/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:30:35 by mnoguera          #+#    #+#             */
/*   Updated: 2022/12/09 17:43:41 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!getdata(argc, argv, stackA))
	{
		write(2, "Error\n", 6);
		return (0);
	}

}

