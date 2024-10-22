
#include <lasm_test.h>

void	test_write(int ac, char **av)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		ft_write(1, av[i], ft_strlen(av[i]));
		ft_write(1, "\n", 1);
		i++;
	}
}
