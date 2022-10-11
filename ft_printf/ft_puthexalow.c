/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexalow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:02:19 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/11 16:27:34 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	hexabaselow(char *base)
{
	int		i;
	char	j;

	i = 0;
	while (i <= 9)
	{
		base[i] = i + 48;
		i++;
	}
	j = 'a';
	while (i < 16)
	{
		base[i] = j;
		i++;
		j++;
	}
	base [i] = '\0';
}

static void	ft_changebase(unsigned int i, char *base)
{
	if (i > 15)
		ft_changebase(i / 16, base);
	write(1, &base[i % 16], 1);
}

void	ft_puthexalow(unsigned int i)
{
	char *base;

	base = malloc(sizeof(char) * 17);	
	if (!base)
		return ;
	hexabaselow(base);
	ft_changebase(i, base);
}
