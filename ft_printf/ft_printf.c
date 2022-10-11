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

static void	oneprint(va_list ap, char s)
{
	if (s == 'c')
		ft_putchar(va_arg(ap, int));
	else if (s == 's')
		ft_putstr(va_arg(ap, char *));
	else if (s == 'p')
		ft_putvoidptr(va_arg(ap, unsigned long));
	else if (s == 'd')
		ft_putdecimal(va_arg(ap, int));
	else if (s == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (s == 'u')
		ft_putunsigdecimal(va_arg(ap, unsigned int));
	else if (s == 'x')
		ft_puthexalow(va_arg(ap, unsigned int));
	else if (s == 'X')
		ft_puthexaupp(va_arg(ap, unsigned int));
	else if (s == '%')
		write(1, "%", 1);
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
			oneprint(ap, str[i]);
		}
		else
			write(1, &str[i], 1);
		len++;
		i++;
	}
	va_end(ap);
	return (i);
}

int main()
{
	ft_printf("%X hola\n", 4342);
	printf("\n%X\n", 4342);
}

