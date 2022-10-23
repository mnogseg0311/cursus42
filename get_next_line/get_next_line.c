/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:26:14 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/21 18:18:43 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	emptyline(char *str)
{
	char	*aux;
	int		i;
	int		j;

	j = strlenvar(str, '\n');
	aux = strdupvar(str, '\0');
	if (!aux)
		return (-1);
	free(str);
	str = malloc(sizeof(char) * (strlenvar(aux, '\0') - j));
	if (!str)
	{
		free(aux);
		return (-1);
	}
	j++;
	i = 0;
	while (aux[j] != '\0')
	{
		str[i] = aux[j];
		i++;
		j++;
	}
	free(aux);
	return (1);
}

int	checkline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

int	getdata(char *str, int fd)
{
	char	*aux;
	int		len;

	len = strlenvar(str, '\0');
	aux = strdupvar(str, '\0');
	if (!aux)
		return (-1);
	free(str);
	str = malloc(sizeof(char) * (len + BUFFER_SIZE));
	if (!str)
	{
		free(aux);
		return (-1);
	}
	strcpyvar(str, aux, 0, strlenvar(aux, '\0') + 1);
	free(aux);
	aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux || read(fd, aux, BUFFER_SIZE) < 0)
	{
		free(aux);
		return (-1);
	}
	strcpyvar(str, aux, strlenvar(aux, '\n'), len + BUFFER_SIZE + 1);
	free(aux);
	return (1);
}

char *get_next_line(int fd)
{
	static char	*str;
	char		*line;

	while (checkline(str) == -1)
		if (getdata(str, fd) == -1)
		{
			free(str);
			return (NULL);
		}
	line = NULL;
	line = strdupvar(str, '\n');
	if (!line || emptyline(str) == -1)
	{
		if (line)
			free(line);
		free(str);
		return (NULL);
	}
	return (line);
}

#include <stdio.h>
int main()
{
	FILE*	fd;
	fd = fopen("fitxer.txt", "r");
	if (!fd)
		return (-1);
	printf("%s", get_next_line(fd));
	fclose(fd);
}
