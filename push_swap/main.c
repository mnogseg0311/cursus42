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

#include "push_swap"

void	push_swap();

int	main(int argc, char **argv)
{
	t_stack	stackA;
	t_stack	stackB;

	if (argc == 1)
		return (1);
	stackB.first = NULL;
	stackB.len = 0;
	if (getinput(argc - 1, argv, stackA) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
}

