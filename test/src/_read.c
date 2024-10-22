
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
		if (ret == 1)
		{
			if (overbuff)
				ft_write(1, "\n", 1);
			if (fd == 0)
				ft_write(1, " > ", 3);
			overbuff = 0;
		}
		else if (ret == 10)
		{
			ft_write(1, buffer, ret);
			overbuff = 1;
		}
		else
		{
			if (fd == 0 && !strcmp(buffer, "exit\n"))
				break;
			if (buffer[ret - 1] == '\0')
				ft_write(1, buffer, ret);
			else if (buffer[ret - 1] == '\n')
			{
				ft_write(1, buffer, ret);
				if (fd == 0)
					ft_write(1, " > ", 3);
			}
			overbuff = 0;
		}
	}
}

void	test_read(int ac, char **av)
{
	char	buffer[11];
	int		fd;
	int		i;

	i = 0;
	buffer[10] = '\0';
	if (ac != 0)
	{
		while (i < ac)
		{
			if ((fd = open(av[i], O_RDONLY)) != -1)
			{
				printf("file:%d open\n", i + 1);
				do_read(fd, buffer);
				close(fd);
				printf("file:%d closed\n", i + 1);
			}
			i++;
		}
	}
	else
	{
		if (!ft_strcmp(av[1], "ft_read"))
		{
			ft_write(1, "type text (\"exit\" for leave)\n > ", 32);
			do_read(0, buffer);
		}
		else
			printf("%s\n", av[1]);
	}
}
