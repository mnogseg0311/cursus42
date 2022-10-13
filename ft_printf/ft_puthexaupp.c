/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaupp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:29 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 16:11:12 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	hexabaseupp(char *base)
{
	int		i;
	char	j;

	i = 0;
	while (i <= 9)
	{
		base[i] = i + 48;
		i++;
	}
	j = 'A';
	while (i < 16)
	{
		base[i] = j;
		i++;
		j++;
	}
	base [i] = '\0';
}

static void	ft_changebase(unsigned int i, char *base, int *aux)
{
	if (i > 15)
		ft_changebase(i / 16, base, aux);
	*aux += write(1, &base[i % 16], 1);
}

int	ft_puthexaupp(unsigned int i)
{
	char	*base;
	int		aux;

	base = malloc(sizeof(char) * 17);
	if (!base)
		return (0);
	hexabaseupp(base);
	ft_changebase(i, base, &aux);
	return (aux);
}
