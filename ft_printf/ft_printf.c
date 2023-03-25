/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:02:35 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/13 20:30:29 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	oneprint(va_list ap, char s, int len)
{
	int	aux;

	aux = 0;
	if (s == 'c')
		aux = ft_putchar(va_arg(ap, int), len);
	else if (s == 's')
		aux = ft_putstr(va_arg(ap, char *), len);
	else if (s == 'p')
		aux = ft_putvoidptr(va_arg(ap, unsigned long), len);
	else if (s == 'd' || s == 'i')
		aux = ft_putnbr(va_arg(ap, int), len);
	else if (s == 'u')
		aux = ft_putunsigdecimal(va_arg(ap, unsigned int), len);
	else if (s == 'x')
		aux = ft_puthexalow(va_arg(ap, unsigned int), len);
	else if (s == 'X')
		aux = ft_puthexaupp(va_arg(ap, unsigned int), len);
	else if (s == '%')
		aux = ft_putchar(37, len);
	return (aux);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (len == -1)
			return (len);
		if (str[i] == '%')
		{
			i++;
			len = oneprint(ap, str[i], len);
		}
		else
			len = ft_putchar(str[i], len);
		i++;
	}
	va_end(ap);
	return (len);
}
/*
int main()
{
	ft_printf("%d hola\n", 43/42);
	printf("%i\n", 43/42);
}
*/
