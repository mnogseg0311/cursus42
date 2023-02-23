/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoguera <mnoguera@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:03:59 by mnoguera          #+#    #+#             */
/*   Updated: 2023/02/23 17:27:12 by mnoguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*recorre l’array amb dos auxiliars, una conta quants n’hi ha de més petits i l‘altre quants n’hi ha de més grans, retorna el game_num ó -1 si està repetit */

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

t_piece	*new_node(void)
{
	t_piece	*new;

	new = malloc(sizeof(t_piece));
	new->num = 0;
	new->game_num = 0;
	new->next = NULL;
	return (new);
}

t_piece	*get_list(int *data, int len)
{
	int	i;
	t_piece *first;
	t_piece	*aux;
	
	first = new_node();
	aux = first;
	i = 0;
	while (i < len)
	{
		aux->game_num = game_number(data[i], data, len);
		aux->num = data[i];
		if (i < len - 1)
		{
			aux->next = new_node();
			aux = aux->next;
		}
		i++;
	}
	return (first);
}

/*retorna 0 si el nombre es passa del limit dels enters i 1 en cas contrari*/

int	check_limit(char *num, int len)
{
	int	i;

	i = 0;
	if (len > 11 || (len == 11 && num[0] != '-' && num[0] != '+'))
		return (0);
	if (len == 10 && ft_strncmp(num, "2147483647", 10) > 0)
		return (0);
	else if (num[0] == '-' && ft_strncmp(num, "-2147483648", 11) > 0)
		return (0);
	else if (num[0] == '+' && ft_strncmp(num, "+2147483647", 11) > 0)
                return (0);
	return (1);
}

int	is_int(char *number)
{
	int	i;
	int	len;

	i = 0;
	number = ft_strtrim(number, "0");
	len = ft_strlen(number);
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i] != '\0')
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	if (len >= 10)
		return (check_limit(number, len));
	return (1);
}

int	count_nums(char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			while (str[i] == ' ' || str[i] == '	')
				i++;
		}
		else
		{
			num++;
			while (str[i] != ' ' && str[i] != '	' && str[i] != '\0')
				i++;
		}
	}
	return (num);
}

t_piece	*getdata(int len, char **str)
{
	printf("len = %d\n", len);
	int	*data;
	int	i;
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
	first = get_list(data, len);
	free(data);
	return (first);
}

t_piece	*getinput(int argc, char **argv)
{
	if (argc == 2)
		return (getdata(count_nums(argv[1]), ft_split(ft_strjoin("./a.out ", argv[1]), ' ')));
	return (getdata(argc - 1, argv));
}


//s'ha de controlar errors tipus quan estan repetits
//accepta l'input 0000+2 o 00-6 com a 0
//el pol diu que no ho hauria d'agafar, com a molt -0005 i ho fa posant fins a 9 0's
