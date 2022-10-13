/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:35:33 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 20:32:15 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putnum(int n, int *aux, int len)
{
	if (n > 9)
		ft_putnum(n / 10, aux, len);
	if (*aux != -1)
		*aux += ft_putchar(n % 10 + 48, len);
}

int	ft_putnbr(int n, int len)
{
	int	aux;

	aux = 0;
	if (n == -2147483648)
		aux = write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			aux = write(1, "-", 1);
			n = -n;
		}
		ft_putnum(n, &aux, len);
	}
	if (aux < 0)
		return (aux);
	return (aux + len);
}
