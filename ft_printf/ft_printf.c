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
		printchar(va_arg(ap, ));
	else if (s == 's')
		printstr(va_arg(ap, ));
	else if (s == 'p')
		printvoidp(va_arg(ap, ));
	else if (s == 'd')
		prindecimal(va_arg(ap, ));
	else if (s == 'i')
		printint(va_arg(ap, ));
	else if (s == 'u')
		printudecimal(va_arg(ap, ));
	else if (s == 'x')
		printhexalow(va_arg(ap, ));
	else if (s == 'X')
		printhexaupp(va_arg(ap, ));
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

int main()
{
	ft_printf("% ");
}
