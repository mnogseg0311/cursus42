/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:58:46 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/27 16:21:00 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!str[fd] || !ft_strchr(str[fd], '\n'))
		str[fd] = getdata(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = NULL;
	line = ft_strdup(str[fd]);
	if (!line)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = emptyline(str[fd]);
	return (line);
}
