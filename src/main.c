
#include <stdio.h>
#include <stdlib.h>

extern size_t _ft_strlen(char *str);
extern char *_ft_strcpy(char *dest, const char *src);

int main(int ac, char **av)
{
    size_t i;
    char *str;

    i = 0;
    if (ac > 1)
    {
        i = _ft_strlen(av[1]);
        str = (char *)malloc((sizeof(char) * i) + 1);
        _ft_strcpy(str, av[1]);
        str[i] = '\0';
        printf("len:%zu;av[1]:%s;str:%s\n", i, av[1], str);
    }
    return (0);
}