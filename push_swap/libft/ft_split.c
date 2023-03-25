/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:03:35 by mnoguera          #+#    #+#             */
/*   Updated: 2023/03/14 15:49:51 by mnoguera         ###   ########.fr       */
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

static char	*get_word(char const *s, char c, int i)
{
	int		j;
	int		k;
	int		len;
	char	*word;

	j = 0;
	k = 0;
	while (k < i)
	{
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
			j++;
		k++;
	}
	while (s[j] == c)
		j++;
	len = j;
	while (s[len] != c && s[len] != '\0')
		len++;
	len -= j;
	word = ft_substr(s, j, len);
	if (!word)
		return (NULL);
	return (word);
}

static int	ft_fillmat(char const *s, char c, char **mat, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		mat[i] = get_word(s, c, i);
		if (!mat[i])
		{
			ft_free_malloc(mat, i);
			return (0);
		}
		i++;
	}
	mat[i] = NULL;
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
