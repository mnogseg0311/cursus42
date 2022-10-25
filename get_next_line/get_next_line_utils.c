/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:27:23 by mnoguera          #+#    #+#             */
/*   Updated: 2022/10/25 21:23:50 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	strlenvar(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	if (str && c != '\0')
		i++;
	return (i);
}


char *ft_strjoin(char *s1, char *s2)
{
	char *result;
	int i;
	int j;

	i = 0;
	j = 0;
	if(!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if(!s1)
			return(NULL);
		s1[0] = '\0';
	}
	result = malloc(sizeof(char) * (strlenvar(s1, '\0') + strlenvar(s2, '\0') + 1));
	if(!result)
	{
		free(s1);
		return(NULL);

	}
	while(s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[j+i] = '\0';
	free(s1);
	//printf("strjoin une |%s|\n", result);
	return(result);
}

char	*strdupvar(char *str, char c)
{
	//printf("Entro a strdupvar\n");
	//printf("str vale = |%s|\n", str);

	int		i;
	char	*cpy;
	(void)c;
	i = 0;

	if(!str[i])
		return(NULL);
	while(str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\n')
		cpy = malloc(sizeof(char) * (i + 2));
	else
		cpy = malloc(sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	//printf("Reservo memoria\n");
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		cpy[i] = str[i];
		i++;
	}
	//printf("Despues del while\n");
	if (str[i] == '\n')
	{
		
		cpy[i] = '\n';
		i++;
	}
	//printf("Despues de c!=0\n");
	cpy[i] = '\0';
//	printf("Despues de strdupvar |%s|\n", cpy);
	return (cpy);
}

void	strcpyvar(char *dst, char *src, int i, int size)
{
	int	j;

	j = 0;
	while (j < size && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	//printf("Despues de trcpyvar devolvemos |%s|\n", dst);
}

char    *ft_strchr(const char *s, int c)
{
	//printf("strchr in action\n");
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
		{
			//printf("strchr salida 1\n");
            return ((char *)&s[i]);
		}
		i++;
    }
    if (s[i] == (char)c)
	{
		//printf("strchr salida 2\n");
        return ((char *)&s[i]);
	}
	//printf("strchr salida 3\n");
	return (NULL);
}
