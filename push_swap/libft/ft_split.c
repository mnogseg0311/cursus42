/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:43:07 by mnoguera          #+#    #+#             */
/*   Updated: 2022/09/27 15:42:03 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_malloc(char **mat, int i)
{
	i--;
	while (i >= 0)
	{
		free(mat[i]);
		i--;
	}
	free(mat);
}

static int	ft_fillaux(char const *s, char c, char **mat, int v[])
{
	while (v[3] < v[0])
	{
		if (s[v[1]] == c)
			while (s[v[1]] == c)
				v[1]++;
		else
		{
			v[2] = v[1];
			v[4] = 0;
			while (s[v[1]] != c && s[v[1]] != '\0')
			{
				v[1]++;
				v[4]++;
			}
			mat[v[3]] = ft_substr(s, v[2], v[4]);
			if (!mat[v[3]])
			{
				ft_free_malloc(mat, v[3]);
				return (0);
			}
			v[3]++;
		}
	}
	mat[v[3]] = NULL;
	return (1);
}

static int	ft_fillmat(char const *s, char c, char **mat, int words)
{
	int	i;
	int	aux;
	int	j;
	int	len;
	int	vect[5];

	aux = 0;
	j = 0;
	i = 0;
	len = 0;
	vect[0] = words;
	vect[1] = i;
	vect[2] = aux;
	vect[3] = j;
	vect[4] = len;
	if (!ft_fillaux(s, c, mat, vect))
		return (0);
	return (1);
}

static int	ft_words(char const *s, char c)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else
		{
			num++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (num);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		words;

	words = ft_words(s, c);
	mat = (char **)malloc(sizeof(char *) * (words + 1));
	if (!mat || !ft_fillmat(s, c, mat, words))
		return (NULL);
	return (mat);
}
