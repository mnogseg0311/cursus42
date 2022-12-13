#include "push_swap.h"

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

/*per cada int crea una nova peça posant-hi el game_num*/
#include <stdio.h>
int	fill_stack(t_stack *stackA, int *data, int len)
{
	int	i;
	int	game_num;

	i = 0;
	while (i < len)
	{
		printf("al while\n");
		game_num = game_number(data[i], data, len);
		printf("i=%d, data[i]=%d, game_num=%d\n", i, data[i], game_num);
		if (game_num == -1)
			return (0);
		if (!add_piece(last_piece(stackA->first), data[i], game_num))
		{
		//	free_pieces(&stackA.first);
			return (0);
		}
		printf("stackA->first->num=%d\n", stackA->first->num);
		stackA->len++;
		printf("stackA->len=%d\n", stackA->len);
		i++;
	}
	return (1);
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

/*retorna 1 si l'input es valid i 0 en cas contrari*/

int	is_int(char *number)
{
	int	i;
	int	len;

	i = 0;
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

/*comprova que l'input rebut sigui correcte i el desa en l'stackA, si hi ha algun error, retorna 0, si tot va be, 1*/

int	getdata(int argc, char **argv, t_stack *stackA)
{
	int	*data;
	int	i;

	data = malloc(sizeof(int) * (argc - 1));
	if (!data)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
		{
			free(data);
			return (0);
		}
		data[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (!fill_stack(stackA, data, argc - 1))
	{
		free(data);
		return (0);
	}
	printf("Un cop ja ple, stackA.len=%d\n", stackA->len);
	free(data);
	return (1);
}
