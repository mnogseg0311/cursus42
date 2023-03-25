/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:33:44 by mnoguera          #+#    #+#             */
/*   Updated: 2022/09/26 17:40:07 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_num(int n, int s, int j, char *num)
{
	int	i;
	int	aux;

	num[j] = '\0';
	i = 0;
	if (s < 0)
	{
		num[0] = '-';
		i++;
	}
	j--;
	aux = 0;
	while (j >= i)
	{
		aux = n % 10;
		n = n / 10;
		num[j] = aux + 48;
		j--;
	}
	return (num);
}

static int	count(int n)
{
	int	aux;
	int	j;

	j = 0;
	aux = n;
	if (aux == 0)
		j++;
	while (aux != 0)
	{
		aux = aux / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	int		s;
	int		j;
	char	*num;

	s = 1;
	j = 0;
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	if (n < 0)
	{
		n = -n;
		s = -s;
		j++;
	}
	j += count(n);
	num = (char *)malloc(j + 1);
	if (!num)
		return (NULL);
	num = ft_num(n, s, j, num);
	return (num);
}
/*
int	main()
{
	printf("%s", ft_itoa(-2147483648));
}
*/
