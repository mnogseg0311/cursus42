/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:24:24 by mnoguera          #+#    #+#             */
/*   Updated: 2022/09/20 14:20:44 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
