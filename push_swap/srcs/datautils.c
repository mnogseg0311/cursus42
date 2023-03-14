#include "../includes/push_swap.h"

/*conta quants nombres hi ha en cas que l'inpot el posn com a string*/

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

/*comprova si es un enter dins del limit*/

int	is_int(char *number)
{
	int	i;
	int	len;

	i = 0;
	number = trim_zeros(number);
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

/*depura els 0's del nombre, accepta signe al davant*/

char	*trim_zeros(char *num)
{
	int		i;
	int		j;
	int		s;
	int		len;
	char	*trimed;

	i = 0;
	if (num[i] == '+' || num [i] == '-')
		i++;
	s = i;
	while (num[i] == '0')
		i++;
	if (num[i] == '\0')
		return ("0");
	len = ft_strlen(num);
	trimed = malloc(sizeof(char) * (len - i + s));
	if (!trimed)
		return (NULL);
	if (s)
		trimed[0] = num[0];
	j = s - 1;
	i--;
	while (num[i] != '\0')
		trimed[j++] = num[i++];
	return (trimed);
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