
#include <lasm_test.h>

int		count_char(int nb)
{
	int		i;
	long	number;

	i = 0;
	number = (long)nb;
	if (nb < 0)
	{
		i = 1;
		number = -number;
	}
	while (number > 0 && ++i)
		number = number / 10;
	return (i);
}

char	*itoa(int nb, char *number)
{
	long	mem;
	int		i;

	mem = (long)nb;
	number[0] = '-';
	i = count_char(nb);
	number[i] = '\0';
	if (nb < 0)
		mem = -mem;
	else if (nb == 0)
		number[0] = '0';
	while (mem > 0 && i--)
	{
		number[i] = ((int)(mem % 10) + '0');
		mem = mem / 10;
	}
	return (number);
}

void	write_number(int nb)
{
	int		i;
	char	*number;

	i = 0;
	number = (char *)malloc(sizeof(char) * 12);
	if (number)
	{
		while (i < 12)
			number[i++] = '\0';
		itoa(nb, number);
		shrink_write(number);
		free(number);
	}
}

void	shrink_write(char *str)
{
	ft_write(1, str, ft_strlen(str));
}

void	test_write(int ac, char **av)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		shrink_write(av[i]);
		shrink_write("\n");
		i++;
	}
}
