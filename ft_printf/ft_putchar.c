/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:28:34 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 21:11:40 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(int c, int len)
{
	int	aux;

	aux = write(1, &c, 1);
	if (aux < 0)
		return (aux);
	return (aux + len);
}
