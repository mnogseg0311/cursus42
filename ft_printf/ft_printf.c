/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:02:35 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/11 16:36:06 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

static int	oneprint(va_list ap, char s)
{
	int	aux;

	if (s == 'c')
		aux = ft_putchar(va_arg(ap, int));
	else if (s == 's')
		aux = ft_putstr(va_arg(ap, char *));
	else if (s == 'p')
		aux = ft_putvoidptr(va_arg(ap, unsigned long));
	else if (s == 'd' || s == 'i')
		aux = ft_putnbr(va_arg(ap, int));
	else if (s == 'u')
		aux = ft_putunsigdecimal(va_arg(ap, unsigned int));
	else if (s == 'x')
		aux = ft_puthexalow(va_arg(ap, unsigned int));
	else if (s == 'X')
		aux = ft_puthexaupp(va_arg(ap, unsigned int));
	else if (s == '%')
		aux = write(1, "%", 1);
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
		if (str[i] == '%')
		{
			i++;
			len += oneprint(ap, str[i]);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

int main()
{
	ft_printf("%X hola\n", 4342);
	printf("\n%X\n", 4342);
}

