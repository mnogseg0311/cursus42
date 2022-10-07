/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:02:35 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/07 15:43:53 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	oneprint(va_list ap, char s, int i)
{
	if (str[i] == '\\')
	{
		printescseq(s, i);
		return ;
	}
	if (s == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (s == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (s == 'p')
		printvoidp(va_arg(ap, unsigned long));
	else if (s == 'd')
		prindecimal(va_arg(ap, int));
	else if (s == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (s == 'u')
		printudecimal(va_arg(ap, unsigned int));
	else if (s == 'x')
		printhexalow(va_arg(ap, unsigned int));
	else if (s == 'X')
		printhexaupp(va_arg(ap, unsigned int));
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
			oneprint(ap, str[i], i);
			len++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (i);
}

#include <stdio.h>
int main()
{
	ft_printf("% ");
}
