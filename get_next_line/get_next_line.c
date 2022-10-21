/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:26:14 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/21 16:08:16 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line"

int	emptyline(static char *str)
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

int	getdata(static char *str)
{
	char	*aux;
	int		len;

	len = strlenvar(str, '\0');
	aux = ft_strdup(str);
	if (!aux)
		return (-1);
	free(str);
	str = malloc(sizeof(char) * (len + BUFFER_SIZE));
	if (!str)
	{
		free(aux);
		return (-1);
	}
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
		if (getdata(str) == -1)
		{
			free(str);
			return (NULL);
		}
	line = NULL;
	line = copyline(str);
	if (!line || emptyline(str) == -1)
	{
		if (line)
			free(line);
		free(str);
		return (NULL);
	}
	return (line);
}
