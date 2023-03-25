/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:19:08 by mnoguera          #+#    #+#             */
/*   Updated: 2022/09/20 16:57:46 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	if (!dst && !src)
		return (dst);
	a = (char *)dst;
	b = (char *)src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int	main()
{
	char a[20] = "helloooooo";
	char b[20] = "marta";
	char *p = &a[0];
	char *q = &b[0];
	printf("%s", ft_memcpy((void *)0, (void *)0,  3));
}
*/
