/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:35:33 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/11 15:17:35 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void ft_putnum(int n, int *aux)
{
	if (n > 9)
		ft_putnum(n / 10);
	*aux += ft_putchar(n % 10 + 48);
}

int	ft_putnbr(int n)
{
	int	aux;

	aux = 0;
	if (n == -2147483648)
		aux = write(1, "-2147483648", 1);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			aux++;
		}
		ft_putnum(n, &aux);
	}
	return (aux);
}
