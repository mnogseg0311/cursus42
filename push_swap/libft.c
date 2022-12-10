int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int     ft_strncmp(const char *s1, const char *s2, int n)
{
        int  i;

        i = 0;
        while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
        {
                if (s1[i] != s2[i])
                        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                i++;
        }
        return (0);
}

int     ft_atoi(const char *str)
{
        int     i;
        int     j;
        int     num;

        i = 0;
        j = 1;
        num = 0;
        while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
                i++;
        if (str[i] == '+' || str[i] == '-')
        {
                if (str[i] == '-')
                        j = -1 * j;
                i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {
                num = num * 10 + str[i] - 48;
                i++;
        }
        if (j == -1)
                num = -1 * num;
        return (num);
}

