
#include <lasm_test.h>

void	test_strcpy(int ac, char **av)
{
	int		i;
	int		len;
	char	**cpy;

	i = 0;
	len = 0;
	
	ft_write(1, "testing ft_strcpy\n", 18);
	cpy = (char **)malloc(sizeof(char *) * ac);
	if (cpy != NULL)
	{
		while (i < ac)
		{
			len = ft_strlen(av[i]);
			cpy[i] = (char *)malloc((sizeof(char) * len) + 1);
			ft_strcpy(cpy[i], av[i]);
			ft_write(1, cpy[i], len);
			ft_write(1, "\n", 1);
			free(cpy[i]);
			i++;
		}
		free(cpy);
	}
}
