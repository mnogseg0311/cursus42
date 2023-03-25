/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:58:46 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/26 19:49:44 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*nicefree(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*emptyline(char *str)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (!str || !str[i])
		return (nicefree(&str));
	aux = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!aux)
		return (nicefree(&str));
	i++;
	while (str[i + j++] != '\0')
		aux[j - 1] = str[i + j - 1];
	if (j - 1 > 0)
		aux[j - 1] = '\0';
	else
	{
		free(aux);
		return (nicefree(&str));
	}
	nicefree(&str);
	return (aux);
}

char	*getdata(char *str, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readbytes;

	readbytes = 1;
	buffer[0] = '\0';
	while (readbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes > 0)
		{
			buffer[readbytes] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	if (readbytes < 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str || !ft_strchr(str, '\n'))
		str = getdata(str, fd);
	if (!str)
		return (NULL);
	line = NULL;
	line = ft_strdup(str);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = emptyline(str);
	return (line);
}
