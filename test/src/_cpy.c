/* Nice42Header */

#include <lasm_test.h>

void	process_copy(int ac, char **av, char **cpy)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		cpy[i] = (char *)malloc((sizeof(char) * len) + 1);
		ft_strcpy(cpy[i], av[i]);
		shrink_write(cpy[i]);
		shrink_write("\n");
		free(cpy[i]);
		i++;
	}
}

void	test_strcpy(int ac, char **av)
{
	char	**cpy;

	if (ac == 0)
	{
		shrink_write("usage ./name ft_strcpy args ...\n");
		return ;
	}
	shrink_write("testing ft_strcpy\n");
	cpy = (char **)malloc(sizeof(char *) * ac);
	if (cpy != NULL)
	{
		process_copy(ac, av, cpy);
		if (ac == 1)
			shrink_write("Je jure que c'est une copie !\n");
		else
			shrink_write("Je jure que c'est des copies !\n");
		free(cpy);
	}
}
