
#include <lasm_test.h>





char	*itoa(int nb)
{
	char	number[12];
	int		neg;
	long	mem;
	int		i;

	neg = 0;
	mem = nb;
	if (nb < 0)
	{
		mem = -nb;
		neg = -1;
	}
	i = -neg;
	while (++i && mem / 10 > 1)
		mem = mem / 10;
	printf("nb:%d\ni:%d\n", nb, i);
	while (nb > 1 && i--)
	{
		number[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return ("ok");
}

void	test_strlen(int ac, char **av)
{
	int 	i;
	int		len;

	i = 0;
	len = 0;
	ft_write(1, "testing ft_strlen\n", 18);
	while (i < ac)
	{
		itoa(atoi(av[i]));
		len = ft_strlen(av[i]);
		printf("av:%d\tlen = %d\n", i, len);
		i++;
	}
}