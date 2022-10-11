/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigdecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:03:45 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/10 17:03:48 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

static char*	ft_utoa(unsigned int n)
{
}

int	ft_putunsigdecimal(unsigned int n)
{
	int		aux;
	char	*nb;

	aux = 0;
	if (n == 0)
		aux = write(1, "0", 1);
	else
	{
		nb = ft_utoa(n);
		aux += ft_putstr(nb);
		free(nb);
	}
	return (aux);
}
