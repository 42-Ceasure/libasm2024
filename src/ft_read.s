;ssize_t _ft_read(int fd, void buf[.count], size_t count);

bits 64

global _ft_read

section .text

    _ft_read:
        mov rax, 0
        syscall
        jc error
        ret

    error:
        mov rax, -1
        ret
