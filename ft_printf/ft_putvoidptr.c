/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoidptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:04:02 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 20:42:44 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putptr(unsigned long p, int *aux, char *base)
{
	if (p > 15)
		ft_putptr(p / 16, aux, base);
	if (*aux != -1)
		*aux += write(1, &base[p % 16], 1);
}

int	ft_putvoidptr(unsigned long p, int len)
{
	int		aux;
	char	*base;

	base = "0123456789abcdef";
	aux = ft_putstr("0x", len);
	if (aux < 0)
		return (aux);
	aux = 0;
	ft_putptr(p, &aux, base);
	if (aux < 0)
		return (aux);
	return (len + aux + 2);
}
