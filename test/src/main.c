// Entiers de 64 bits : rdi, rsi, rdx, rcx, r8, r9

// Registres sauvegardés par l'appelé
// rbx, rbp, rsp, r12, r13, r14, r15

// Registres sauvegardés par l'appelant
// rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11

#include <lasm_test.h>

void	sort(int ac, char **av)
{
	if (!ft_strcmp(av[1], "ft_strlen"))
		test_strlen(ac - 2, av + 2);
	if (!ft_strcmp(av[1], "ft_strcpy"))
		test_strcpy(ac - 2, av + 2);
	if (!ft_strcmp(av[1], "ft_strcmp"))
		test_strcmp(ac - 2, av + 2);
	if (!ft_strcmp(av[1], "ft_write"))
		test_write(ac - 2, av + 2);
	if (!ft_strcmp(av[1], "ft_strdup"))
		test_strdup(ac - 2, av + 2);
	if (!ft_strcmp(av[1], "ft_read"))
		test_read(ac - 2, av + 2);
}

int		main(int ac, char **av)
{
	if (ac > 2)
		sort(ac, av);
	else if (ac == 2)
		test_read(0, av);
	else
		ft_write(1, "usage\t: ./name fonction arg ...\n", 32);
	return (0);
}
