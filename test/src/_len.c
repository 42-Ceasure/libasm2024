/* Nice42Header */

#include <lasm_test.h>

void	test_strlen(int ac, char **av)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (ac == 0)
	{
		shrink_write("usage ./name ft_strlen args ...\n");
		return ;
	}
	shrink_write("testing ft_strlen\n");
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		write_number(len);
		shrink_write("\n");
		i++;
	}
}
