
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
				shrink_write("\n");
			if (fd == 0)
				shrink_write(" > ");
			overbuff = 0;
		}
		else if (ret == 10)
		{
			shrink_write(buffer);
			overbuff = 1;
		}
		else
		{
			if (fd == 0 && !ft_strcmp(buffer, "exit\n"))
				break;
			if (buffer[ret - 1] == '\0')
				shrink_write(buffer);
			else if (buffer[ret - 1] == '\n')
			{
				shrink_write(buffer);
				if (fd == 0)
					shrink_write(" > ");
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
				// printf("file:%d open\n", i + 1);
				do_read(fd, buffer);
				close(fd);
				// printf("file:%d closed\n", i + 1);
			}
			i++;
		}
	}
	else
	{
		if (!ft_strcmp(av[1], "ft_read"))
		{
			shrink_write("type text (\"exit\" for leave)\n > ");
			do_read(0, buffer);
		}
		else
		{
			shrink_write(av[1]);
			shrink_write("\n");
		}
	}
}
