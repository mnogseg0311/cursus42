/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:03:59 by mnoguera          #+#    #+#             */
/*   Updated: 2023/03/16 19:32:49 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*recorre l’array amb dos auxiliars, un conta quants n’hi ha de més petits i 
l‘altre quants n’hi ha de més grans, retorna el game_num ó -1 si està repetit*/

int	game_number(int	num, int *data, int len)
{
	int	i;
	int	repeats;
	int	lower;

	i = 0;
	repeats = 0;
	lower = 0;
	while (i < len)
	{
		if (data[i] == num)
			repeats++;
		if (repeats > 1)
			return (-1);
		if (data[i] < num)
			lower++;
		i++;
	}
	return (lower);
}

/*crea la llista de peces, retorna NULL si hi ha repeticions*/

t_piece	*get_list(int *data, int *game_nums, int len)
{
	int	i;
	t_piece *first;
	t_piece	*aux;
	t_piece	*previous;

	if (!game_nums)
		return (NULL);
	first = new_piece();
	aux = first;
	previous = NULL;
	i = 0;
	while (i < len)
	{
		aux->game_num = game_nums[i];
		aux->num = data[i];
		aux->prev = previous;
		if (i < len - 1)
		{
			previous = aux;
			aux->next = new_piece();
			aux = aux->next;
		}
		i++;
	}
	return (first);
}

/*crea un array amb els game numbers*/

int	*game_numbers(int *data, int len)
{
	int	*gnums;
	int	i;

	gnums = malloc(sizeof(int) * len);
	if (!gnums)
		return (NULL);
	i = 0;
	while (i < len)
	{
		gnums[i] = game_number(data[i], data, len);
		if (gnums[i] < 0)
		{
			free(gnums);
			return (NULL);
		}
		i++;
	}
	return (gnums);
}

/*crea un array amb les dades, comprova que son corretes i envia a fer la llista*/

t_piece	*getdata(int len, char **str)
{
	int		*data;
	int		i;
	t_piece	*first;

	data = malloc(sizeof(int) * len);
	if (!data)
		return (NULL);
	i = 1;
	while (i <= len)
	{
		if (!is_int(str[i]))
		{
			free(data);
			return (NULL);
		}
		data[i - 1] = ft_atoi(str[i]);
		i++;
	}
	first = get_list(data, game_numbers(data, len), len);
	free(data);
	return (first);
}

/*separa cas de tenir l'input en un sol string o sense*/

t_piece	*getinput(int argc, char **argv)
{
	if (argc == 2)
		return (getdata(count_nums(argv[1]), ft_split(ft_strjoin("./a.out ", argv[1]), ' ')));
	return (getdata(argc - 1, argv));
}
