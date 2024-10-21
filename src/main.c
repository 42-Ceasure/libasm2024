// Entiers de 64 bits : rdi, rsi, rdx, rcx, r8, r9

// Registres sauvegardés par l'appelé
// rbx, rbp, rsp, r12, r13, r14, r15

// Registres sauvegardés par l'appelant
// rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

extern size_t _ft_strlen(char *str);
extern char *_ft_strcpy(char *dest, const char *src);
extern int _ft_strcmp(const char *s1, const char *s2);
extern ssize_t _ft_write(int fd, const void *buf, size_t count);
extern ssize_t _ft_read(int fd, void *buf, size_t count);
extern char *_ft_strdup(const char *str_alpha);

void	test_strlen(int ac, char **av)
{
	int 	i;
	int		len;

	i = 0;
	len = 0;
	_ft_write(1, "testing ft_strlen\n", 18);
	while (i < ac)
	{
		len = _ft_strlen(av[i]);
		printf("av:%d\tlen = %d\n", i, len);
		i++;
	}
}

void	test_strcpy(int ac, char **av)
{
	int		i;
	int		len;
	char	**cpy;

	i = 0;
	len = 0;
	
	_ft_write(1, "testing ft_strcpy\n", 18);
	cpy = (char **)malloc(sizeof(char *) * ac);
	if (cpy != NULL)
	{
		while (i < ac)
		{
			len = _ft_strlen(av[i]);
			cpy[i] = (char *)malloc((sizeof(char) * len) + 1);
			_ft_strcpy(cpy[i], av[i]);
			_ft_write(1, cpy[i], len);
			_ft_write(1, "\n", 1);
			free(cpy[i]);
			i++;
		}
		free(cpy);
	}
}

void	test_strcmp(int ac, char **av)
{
	if (ac != 2)
	{
		_ft_write(1, "usage ./name ft_strcmp arg arg", 30);
		_ft_write(1, "\n", 1);
		return ;
	}
	_ft_write(1, "testing ft_strcmp\n", 18);
	printf("comparing %s and %s\n", av[0], av[1]);
	if (!_ft_strcmp(av[0], av[1]))
		_ft_write(1, "strings are equal", 17);
	else  if (_ft_strcmp(av[0], av[1]) < 0)
	{
		_ft_write(1, av[1], _ft_strlen(av[1]));
		_ft_write(1, " is greater than ", 17);
		_ft_write(1, av[0], _ft_strlen(av[0]));
	}
	else
	{
		_ft_write(1, av[0], _ft_strlen(av[0]));
		_ft_write(1, " is greater than ", 17);
		_ft_write(1, av[1], _ft_strlen(av[1]));
	}
	_ft_write(1, "\n", 1);
}

void	test_write(int ac, char **av)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		_ft_write(1, av[i], _ft_strlen(av[i]));
		_ft_write(1, "\n", 1);
		i++;
	}
}

void	do_read(int fd, char *buffer)
{
	int	ret;
	int overbuff;
	
	ret = 0;
	overbuff = 0;
	while ((ret = _ft_read(fd, buffer, 10)))
	{
		buffer[ret] = '\0';
		if (ret == 1)
		{
			if (overbuff)
				_ft_write(1, "\n", 1);
			if (fd == 0)
				_ft_write(1, " > ", 3);
			overbuff = 0;
		}
		else if (ret == 10)
		{
			_ft_write(1, buffer, ret);
			overbuff = 1;
		}
		else
		{
			if (fd == 0 && !strcmp(buffer, "exit\n"))
				break;
			if (buffer[ret - 1] == '\0')
				_ft_write(1, buffer, ret);
			else if (buffer[ret - 1] == '\n')
			{
				_ft_write(1, buffer, ret);
				if (fd == 0)
					_ft_write(1, " > ", 3);
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
		if (!_ft_strcmp(av[1], "ft_read"))
		{
			_ft_write(1, "type text (\"exit\" for leave)\n > ", 32);
			do_read(0, buffer);
		}
		else
			printf("%s\n", av[1]);
	}
}

void	test_strdup(int ac, char **av)
{
	(void) ac;
	(void) av;
}

void	sort(int ac, char **av)
{
	if (!_ft_strcmp(av[1], "ft_strlen"))
		test_strlen(ac - 2, av + 2);
	if (!_ft_strcmp(av[1], "ft_strcpy"))
		test_strcpy(ac - 2, av + 2);
	if (!_ft_strcmp(av[1], "ft_strcmp"))
		test_strcmp(ac - 2, av + 2);
	if (!_ft_strcmp(av[1], "ft_write"))
		test_write(ac - 2, av + 2);
	if (!_ft_strcmp(av[1], "ft_strdup"))
		test_strdup(ac - 2, av + 2);
	if (!_ft_strcmp(av[1], "ft_read"))
		test_read(ac - 2, av + 2);
}

int		main(int ac, char **av)
{
	if (ac > 2)
		sort(ac, av);
	else if (ac == 2)
		test_read(0, av);
	else
		_ft_write(1, "usage\t: ./name fonction arg ...\n", 32);
	return (0);
}
