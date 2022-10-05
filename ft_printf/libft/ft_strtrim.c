/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:37:47 by mnoguera          #+#    #+#             */
/*   Updated: 2022/09/30 17:33:27 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	finish(char const *s, char const *set)
{
	int	i;
	int	j;
	int	aux;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		aux = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s[i])
				aux++;
			j++;
		}
		if (aux == 0)
			return (i);
		i--;
	}
	return (i);
}

static int	start(char const *s, char const *set)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (s[i] != '\0')
	{
		aux = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s[i])
				aux++;
			j++;
		}
		if (aux == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		f;
	int		i;
	char	*str;

	s = start(s1, set);
	f = finish(s1, set);
	if (f < s)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(f - s + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (i++ <= f - s)
		str[i - 1] = s1[i + s - 1];
	str[i - 1] = '\0';
	return (str);
}
