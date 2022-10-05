/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:10:56 by mnoguera          #+#    #+#             */
/*   Updated: 2022/09/22 18:45:21 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	p = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}
