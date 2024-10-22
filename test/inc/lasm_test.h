#ifndef _TEST_H
# define _TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "libasm.h"

void	test_strlen(int ac, char **av);
void	test_strcpy(int ac, char **av);
void	test_strcmp(int ac, char **av);
void	test_write(int ac, char **av);
void	test_read(int ac, char **av);
void	test_strdup(int ac, char **av);

#endif