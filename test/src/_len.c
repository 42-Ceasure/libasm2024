
#include <lasm_test.h>

void	test_strlen(int ac, char **av)
{
	int 	i;
	int		len;

	i = 0;
	len = 0;
	ft_write(1, "testing ft_strlen\n", 18);
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		printf("av:%d\tlen = %d\n", i, len);
		i++;
	}
}