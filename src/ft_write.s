;ssize_t ft_write(int fd, const void *buf, size_t count);

bits 64

global _ft_write

section .text

    _ft_write:
        mov rax, 1
        syscall
        jc error
        ret

    error:
        mov rax, -1
        ret
