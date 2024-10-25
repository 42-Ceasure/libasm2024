/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _len.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:55:30 by cglavieu          #+#    #+#             */
/*   Updated: 2024/10/25 10:55:31 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lasm_test.h>

void	test_strlen(int ac, char **av)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (ac == 0)
	{
		shrink_write("usage ./name ft_strlen args ...\n");
		return ;
	}
	shrink_write("testing ft_strlen\n");
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		write_number(len);
		shrink_write("\n");
		i++;
	}
}
