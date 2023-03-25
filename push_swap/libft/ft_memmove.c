/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:58:59 by mnoguera          #+#    #+#             */
/*   Updated: 2022/09/21 16:06:37 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if ((!dst && !src) || len == 0)
		return (dst);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (src > dst)
	{
		i = 0;
		while (i++ < len)
			a[i - 1] = b[i - 1];
		return (dst);
	}
	while (len--)
		a[len] = b[len];
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned char a[20] = "abcdefghijklm";
	printf("%s", (unsigned char *)ft_memmove(&a[0], "cba", 3));
}
*/
