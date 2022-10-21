/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:27:23 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/21 18:18:40 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

int	strlenvar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	if (c != '\0')
		i++;
	return (i);
}

char	*strdupvar(char *str, char c)
{
	int		i;
	char	*cpy;

	cpy = malloc(sizeof(char) * (strlenvar(str, c)));
	if (!cpy)
		return (NULL);
	i = 0;
	while (str[i] != c)
	{
		cpy[i] = str[i];
		i++;
	}
	if (c != '\0')
	{
		cpy[i] = c;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	strcpyvar(char dst, char src, int i, int size)
{

}
