/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:27:23 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/21 16:30:16 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

int	strlenvar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	if (c == '\n')
		i++;
	return (i);
}


