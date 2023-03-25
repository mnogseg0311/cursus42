/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:58:25 by mnoguera          #+#    #+#             */
/*   Updated: 2022/09/22 20:18:01 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	if (!s || !f)
		return (0);
	c = ft_strdup(s);
	if (!c)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		c[i] = f(i, c[i]);
		i++;
	}
	return (c);
}
