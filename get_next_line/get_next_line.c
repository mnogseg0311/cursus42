/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:26:14 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/26 17:37:30 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char *nice_free(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
	return(NULL);
}

char *emptyline(char *str)
{
//	printf("hola\n");

	char	*aux;
	int		i;
	int		j;
	int x;

	x = 0;
	j = 0;
	//printf("hola2\n");
	while(str && str[x] && str[x] != '\n')
		x++;
	//printf("hola 2.5\n");
	//printf("x vale = %d\n", x);
	if(!str)
		return(nice_free(&str));
	if(!str[x])
	{
		//printf("hago free y me quiero ir\n");
		return(nice_free(&str));
	}
	aux = malloc(sizeof(char) * (strlenvar(str, '\0') - x + 1));
	if (!aux)
	{
		return (nice_free(&str));
	}
	x++;
	i = 0;
	while (str[x] != '\0')
	{
		aux[j] = str[x];
		x++;
		j++;
	}
	if(j > 0)
		aux[j] = '\0';
	else
	{
		free(aux);
		return(nice_free(&str));
	}
	nice_free(&str);
	return (aux);
}

char *getdata(char *str, int fd)
{
	char buffer[BUFFER_SIZE + 1];
	int read_bytes;
	
	//printf("Entro en get_data\n");
	read_bytes = 1 ;
	buffer[0] = '\0';
	//printf("Antes del hile\n");
	while(read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		//printf("Entrp en el while\n");
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if(read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	//printf("Despues del while de getdata str = |%s|\n", str);
	if(read_bytes == -1)
	{
		free(str);
		return(NULL);
	}
	return(str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	if(!str || (str && !ft_strchr(str, '\n')))
	{
		//printf("Entro en el while de getdata\n");
		str = getdata(str, fd);
	}
	if(!str)
		return(NULL);

//	printf("Despues de gedata str = |%s|\n", str);
	line = NULL;
	line = strdupvar(str, '\n');
//	printf("La nueva linea es = |%s|\n", line);
	if(!line)
	{
		free(str);
		str = NULL;
		return(NULL);
	}
//	printf("Antes de empty\n");
	str =  emptyline(str);
	//printf("Antes de salir en statica = |%s|\n", str);
	return (line);
}
