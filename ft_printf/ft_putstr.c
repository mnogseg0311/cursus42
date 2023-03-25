/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:33:08 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 20:37:41 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int len)
{
	int		aux;

	aux = 0;
	if (!s)
	{
		aux = write(1, "(null)", 6);
		if (aux < 0)
			return (aux);
		return (aux + len);
	}
	aux = write(1, s, ft_strlen(s));
	if (aux < 0)
		return (aux);
	return (aux + len);
}
