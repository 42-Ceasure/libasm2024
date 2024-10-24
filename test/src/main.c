// Entiers de 64 bits : rdi, rsi, rdx, rcx, r8, r9

// Registres sauvegardés par l'appelé
// rbx, rbp, rsp, r12, r13, r14, r15

// Registres sauvegardés par l'appelant
// rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11

#include <lasm_test.h>
#include <stdio.h>

void	custom_test(void)
{
	int		i;

	shrink_write("custom test.\n");
	i = ft_write(1, NULL, 5);
	if (i < 0)
		perror("c_test");
}

void	sort(int ac, char **av)
{
	if (!ft_strcmp(av[1], "ft_strlen"))
		test_strlen(ac - 2, av + 2);
	else if (!ft_strcmp(av[1], "ft_strcpy"))
		test_strcpy(ac - 2, av + 2);
	else if (!ft_strcmp(av[1], "ft_strcmp"))
		test_strcmp(ac - 2, av + 2);
	else if (!ft_strcmp(av[1], "ft_write"))
		test_write(ac - 2, av + 2);
	else if (!ft_strcmp(av[1], "ft_read"))
		test_read(ac - 2, av + 2);
	else if (!ft_strcmp(av[1], "ft_strdup"))
		test_strdup(ac - 2, av + 2);
	else if (!ft_strcmp(av[1], "test"))
		custom_test();
	else
		shrink_write("unknown function.\n");
}

void	hint(void)
{
	shrink_write("usage\t: ./name fonction args ...\n");
	shrink_write("functions available :\n");
	shrink_write("ft_strlen ft_strcpy ft_strcmp");
	shrink_write(" ft_write ft_read ft_strdup\n");
}

int		main(int ac, char **av)
{
	if (ac < 2)
		hint();
	else
		sort(ac, av);
	return (0);
}
