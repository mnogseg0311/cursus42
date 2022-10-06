/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:02:35 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/06 19:42:57 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	oneprint(va_list ap, char s)
{
	if (s == 'c')
		printchar(ap);
	if (s == 's')
		printstr(ap);
	if (s == 'p')
		printvoidp(ap);
	if (s == 'd')
		prindecimal(ap);
	if (s == 'i')
		printint(ap);
	if (s == 'u')
		printudecimal(ap);
	if (s == 'x')
		printhexalow(ap);
	if (s == 'X')
		printhexaupp(ap);
	if (s == '%')
		write(1, "%", 1);
}

int	checkprint(const char *str, int *j, va_list ap)
{
	if (str[*j] != '%')
	{
		write(1, &str[*j], 1);
		return (1);
	}
	*j++;
	if (!ft_strtrim(&str[*j], "csppdiuxX%"))
		return (-1);
	oneprint(ap, str[*j]);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, str);
	while (str[j] != '\0' && checkprint(str, &j, ap))		//ha de sumar a la j
	{
		if (j < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (i);
}
