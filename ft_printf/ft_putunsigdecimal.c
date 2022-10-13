/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigdecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:03:45 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 21:11:37 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	unsignedlen(unsigned int n)
{
	int	aux;

	aux = 0;
	if (n == 0)
		aux++;
	while (n != 0)
	{
		n = n / 10;
		aux++;
	}
	return (aux);
}

static char	*ft_utoa(unsigned int n, int len)
{
	int		aux;
	char	*num;

	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	len--;
	aux = 0;
	while (len >= 0)
	{
		num[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putunsigdecimal(unsigned int n, int len)
{
	int		aux;
	char	*nb;

	aux = 0;
	if (n == 0)
	{
		aux = write(1, "0", 1);
		if (aux < 0)
			return (aux);
	}
	else
	{
		nb = ft_utoa(n, unsignedlen(n));
		aux = ft_putstr(nb, len);
		free(nb);
	}
	return (aux);
}
