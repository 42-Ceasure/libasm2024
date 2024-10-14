bits 64

global _start
extern _ft_strlen
extern _ft_write

section .data

    message db "test", 10

section .text

    _start:
        sub rsp, 8

        mov rdi, message
        call _ft_strlen
        mov r8, rax
        add r8, 1

        add rsp, 8

    print_msg:
        mov rax, 1
        mov rdi, 1
        mov rsi, message
        mov rdx, r8
        call _ft_write

    exit:
        mov rax, 60
        mov rdi, 1
        syscall
