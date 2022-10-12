/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoidptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:04:02 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/12 16:57:35 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putptr(unsigned long p, int *aux, char *base)
{
	if (p > 15)
		ft_putptr(p / 16, aux, base);
	*aux += write(1, &base[p % 16], 1);
}

int	ft_putvoidptr(unsigned long p)
{
	int		count;
	int		aux;
	char	*base;

	base = "0123456789abcdef";
	count = ft_putstr("0x");
	if (p == 0)
		return (count + write(1, "0", 1));
	aux = 0;
	ft_putptr(p, &aux, base);
	count += aux;
	return (count);
}
