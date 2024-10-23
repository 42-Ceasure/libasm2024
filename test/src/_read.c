
#include <lasm_test.h>

void	do_read(int fd, char *buffer)
{
	int	ret;
	int overbuff;
	
	ret = 0;
	overbuff = 0;
	while ((ret = ft_read(fd, buffer, 10)))
	{
		buffer[ret] = '\0';
		if (fd != 0)
			shrink_write(buffer);
		else
		{
			if (!ft_strcmp(buffer, "exit\n"))
				break;
			if (ret != 10)
			{
				if (ret == 1)
				{
					if (overbuff)
					{
						overbuff = 0;
						shrink_write("\n");
					}
					shrink_write(" > ");
				}
				else
				{
					shrink_write(buffer);
					shrink_write(" > ");
				}
			}
			else
			{
				shrink_write(buffer);
				overbuff = 1;
			}
		}
	}
}

void	read_ff(int ac, char **av, char *buffer)
{
	int		fd;
	int		i;

	i = 0;
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) != -1)
		{
			// printf("file:%d open\n", i + 1);
			do_read(fd, buffer);
			close(fd);
			// printf("file:%d closed\n", i + 1);
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
	// else
	// {
	// 	shrink_write(av[1]);
	// 	shrink_write("\n");
	// }
}
