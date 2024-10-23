
#include <lasm_test.h>

void	strings_equal(void)
{
	shrink_write(" strings are equal : ");
	write_number(0);
}

void	string_lower(int diff, int realdiff, char *s2)
{
	shrink_write(s2);
	shrink_write(" is greater ");
	shrink_write(" : ");
	write_number(diff);
	shrink_write(" (real:");
	write_number(realdiff);
	shrink_write(")");
}

void	string_greater(int diff, int realdiff, char *s1)
{
	shrink_write(s1);
	shrink_write(" is greater ");
	shrink_write(" : ");
	write_number(diff);
	shrink_write(" (real:");
	write_number(realdiff);
	shrink_write(")");
}

void	compare_strings(char *s1, char *s2)
{
		int		diff;
		int		realdiff;

		diff = ft_strcmp(s1, s2);
		realdiff = TESTCMP(s1, s2);
		if (diff == 0)
			strings_equal();
		else  if (diff < 0)
			string_lower(diff, realdiff, s2);
		else
			string_greater(diff, realdiff, s1);
		shrink_write("\n");
}

void	test_strcmp(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 2)
	{
		shrink_write("usage ./name ft_strcmp arg args...\n");
		return ;
	}
	shrink_write("testing ft_strcmp\n");
	while (i < ac)
	{
		shrink_write("comparing \"");
		shrink_write(av[0]);
		shrink_write("\" and \"");
		shrink_write(av[i]);
		shrink_write("\".  ");
		compare_strings(av[0], av[i]);
		i++;
	}
}
