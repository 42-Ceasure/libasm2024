/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _write.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:55:46 by cglavieu          #+#    #+#             */
/*   Updated: 2024/10/25 10:55:51 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lasm_test.h>

int	count_char(int nb)
{
	int		i;
	long	number;

	i = 0;
	number = (long)nb;
	if (nb < 0)
	{
		i = 1;
		number = -number;
	}
	while (number > 0 && ++i)
		number = number / 10;
	return (i);
}

char	*itoa(int nb, char *number)
{
	long	mem;
	int		i;

	mem = (long)nb;
	number[0] = '-';
	i = count_char(nb);
	number[i] = '\0';
	if (nb < 0)
		mem = -mem;
	else if (nb == 0)
		number[0] = '0';
	while (mem > 0 && i--)
	{
		number[i] = ((int)(mem % 10) + '0');
		mem = mem / 10;
	}
	return (number);
}

void	write_number(int nb)
{
	int		i;
	char	*number;

	i = 0;
	number = (char *)malloc(sizeof(char) * 12);
	if (number)
	{
		while (i < 12)
			number[i++] = '\0';
		itoa(nb, number);
		shrink_write(number);
		free(number);
	}
}

void	shrink_write(char *str)
{
	ft_write(1, str, ft_strlen(str));
}

void	test_write(int ac, char **av)
{
	int		i;

	if (ac == 0)
	{
		shrink_write("usage ./name ft_write args ...\n");
		return ;
	}
	i = 0;
	while (i < ac)
	{
		shrink_write(av[i]);
		shrink_write("\n");
		i++;
	}
}
