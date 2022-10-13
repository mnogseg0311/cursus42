/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexalow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:02:19 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 16:30:38 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_changebase(unsigned int i, char *base, int *aux)
{
	if (i > 15)
		ft_changebase(i / 16, base, aux);
	*aux += write(1, &base[i % 16], 1);
}

int	ft_puthexalow(unsigned int i)
{
	char	*base;
	int		aux;

	aux = 0;
	base = "0123456789abcdef";
	ft_changebase(i, base, &aux);
	return (aux);
}
