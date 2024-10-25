/* Nice42Header */

#include <lasm_test.h>

void	do_read(int fd, char *buffer)
{
	int	ret;
	int	lastret;

	lastret = 0;
	while (1)
	{
		ret = ft_read(fd, buffer, 10);
		if (ret < 1)
			break ;
		buffer[ret] = '\0';
		if (fd == 0)
		{
			if (!ft_strcmp(buffer, "exit\n"))
				break ;
			if (ret != 1)
				shrink_write(buffer);
			else if (lastret == 10)
				shrink_write("\n");
			if (ret != 10 || buffer[9] == '\n')
				shrink_write(" > ");
			lastret = ret;
		}
		else
			shrink_write(buffer);
	}
}

void	read_ff(int ac, char **av, char *buffer)
{
	int		fd;
	int		i;

	i = 0;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd != -1)
		{
			shrink_write("file open.\n");
			do_read(fd, buffer);
			close(fd);
			shrink_write("file closed.\n");
		}
		i++;
	}
}

void	test_read(int ac, char **av)
{
	char	buffer[11];

	buffer[10] = '\0';
	if (ac != 0)
		read_ff(ac, av, buffer);
	else
	{
		shrink_write("type text (\"exit\" for leave)\n > ");
		do_read(0, buffer);
	}
}
