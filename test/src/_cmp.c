
#include <lasm_test.h>

void	test_strcmp(int ac, char **av)
{
	if (ac != 2)
	{
		ft_write(1, "usage ./name ft_strcmp arg arg", 30);
		ft_write(1, "\n", 1);
		return ;
	}
	ft_write(1, "testing ft_strcmp\n", 18);
	printf("comparing %s and %s\n", av[0], av[1]);
	if (!ft_strcmp(av[0], av[1]))
		ft_write(1, "strings are equal", 17);
	else  if (ft_strcmp(av[0], av[1]) < 0)
	{
		ft_write(1, av[1], ft_strlen(av[1]));
		ft_write(1, " is greater than ", 17);
		ft_write(1, av[0], ft_strlen(av[0]));
	}
	else
	{
		ft_write(1, av[0], ft_strlen(av[0]));
		ft_write(1, " is greater than ", 17);
		ft_write(1, av[1], ft_strlen(av[1]));
	}
	ft_write(1, "\n", 1);
}
