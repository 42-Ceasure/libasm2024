;char *ft_strcpy(char *dest, const char *src);

bits 64

global _ft_strcpy

section .text

    _ft_strcpy:
        mov rax, rdi

    processing_loop:
        mov r8b, [rsi]
        mov [rdi], r8b
        cmp r8b, 0
        je exit_ft
        inc rsi
        inc rdi
        jmp processing_loop

    exit_ft:
        ret
