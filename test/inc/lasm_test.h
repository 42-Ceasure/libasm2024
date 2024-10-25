/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lasm_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:54:20 by cglavieu          #+#    #+#             */
/*   Updated: 2024/10/25 10:54:27 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LASM_TEST_H
# define LASM_TEST_H

# include <stdlib.h>
# include <fcntl.h>

# include "libasm.h"

# define TESTCMP ft_strcmp

void	test_strlen(int ac, char **av);
void	test_strcpy(int ac, char **av);
void	test_strcmp(int ac, char **av);
void	test_write(int ac, char **av);
void	test_read(int ac, char **av);
void	test_strdup(int ac, char **av);
void	shrink_write(char *str);
void	write_number(int nb);

#endif