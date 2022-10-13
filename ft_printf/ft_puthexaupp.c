/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaupp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:29 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 20:32:35 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_changebase(unsigned int i, char *base, int *aux)
{
	if (i > 15)
		ft_changebase(i / 16, base, aux);
	if (*aux != -1)
		*aux += write(1, &base[i % 16], 1);
}

int	ft_puthexaupp(unsigned int i, int len)
{
	char	*base;
	int		aux;

	aux = 0;
	base = "0123456789ABCDEF";
	ft_changebase(i, base, &aux);
	if (aux < 0)
		return (aux);
	return (aux + len);
}
