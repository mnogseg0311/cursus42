/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:26:14 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/20 17:44:48 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line"

int	getdata(static char *str)
{
	char	*aux;
	int		len;

	len = ft_strlen(str);
	aux = ft_strdup(str);
	if (!aux)
		return (-1);
	free(str);
	str = malloc(sizeof(char) * (len + BUFFER_SIZE));
	if (!str)
		return (-1);
	str = ft_strcpy(aux);
	free(aux);
	aux = malloc(sizeof(char) * BUFFER_SIZE);
	aux = read(fd, aux, BUFFER_SIZE);
	ft_strlcat(str, aux, len + BUFFER_SIZE);
	free(aux);
	return (1);
}

char *get_next_line(int fd)
{
	static char	*str;
	char		*line;

	while (checkline(str) == -1)
		getdata(str);
	line = NULL;
	line = ft_strdup(...);
	emptyline(str);
	return (line);
}
