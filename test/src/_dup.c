/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:55:20 by cglavieu          #+#    #+#             */
/*   Updated: 2024/10/25 10:55:21 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lasm_test.h>

void	process_dup(int ac, char **av, char **cpy)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		cpy[i] = ft_strdup(av[i]);
		shrink_write(cpy[i]);
		shrink_write("\n");
		free(cpy[i]);
		i++;
	}
}

void	test_strdup(int ac, char **av)
{
	char	**cpy;

	if (ac == 0)
	{
		shrink_write("usage ./name ft_strdup args ...\n");
		return ;
	}
	shrink_write("testing ft_strdup\n");
	cpy = (char **)malloc(sizeof(char *) * ac);
	if (cpy != NULL)
	{
		process_dup(ac, av, cpy);
		free(cpy);
	}
}
