/* Nice42Header */

#ifndef LASM_TEST_H
# define LASM_TEST_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

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