/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:35:33 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/14 18:39:28 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static void	ft_putnum(int n, int *aux, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n > 9)
		ft_putnum(n / 10, aux, len);
	if (*aux != -1)
	{
		i = n % 10 + 48;
		j += write(1, &i, 1);
		if (j < 0)
			*aux = -1;
		else
			*aux += j;
	}
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
			if (aux < 0)
				return (aux);
			n = -n;
		}
		ft_putnum(n, &aux, len);
	}
	if (aux < 0)
		return (aux);
	return (aux + len);
}
