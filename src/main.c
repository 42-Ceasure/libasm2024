// Entiers de 64 bits : rdi, rsi, rdx, rcx, r8, r9

// Registres sauvegardés par l'appelé
// rbx, rbp, rsp, r12, r13, r14, r15

// Registres sauvegardés par l'appelant
// rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern size_t _ft_strlen(char *str);
extern char *_ft_strcpy(char *dest, const char *src);
extern int _ft_strcmp(const char *s1, const char *s2);
extern ssize_t _ft_write(int fd, const void *buf, size_t count);
extern ssize_t _ft_read(int fd, void *buf, size_t count);
extern char *_ft_strdup(const char *str_alpha);

int main(int ac, char **av)
{
    size_t  i;
    int     diff;
    int     realdiff;
    char    *str;
    char    buf[64];
    char    *dupstr;

    i = 0;
    diff = 0;
    bzero(buf, 64);
    dupstr = NULL;
    if (ac > 1)
    {
        i = _ft_strlen(av[1]);
        str = (char *)malloc((sizeof(char) * i) + 1);
        _ft_strcpy(str, av[1]);
        printf("av[1]\t:%s\nlen\t:%zu\nstr\t:%s\n", av[1], i, str);
        if (ac > 2)
        {
            i = _ft_strlen(av[2]);
            diff = _ft_strcmp(av[1], av[2]);
            realdiff = strcmp(av[1], av[2]);
            printf("av[2]\t:%s\ndiff\t:%i\nrdiff\t:%i\n", av[2], diff, realdiff);
            _ft_read(1, buf, 63);
            _ft_write(1, buf, 64);
            dupstr = _ft_strdup(buf);
            printf("dupstr\t:%s\n", dupstr);
        }
    }
    return (0);
}