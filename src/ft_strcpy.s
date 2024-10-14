;char *strcpy(char *dest, const char *src);
;               rdi              rsi

bits 64

global _ft_strcpy

section .text

    _ft_strcpy:
        mov rax, rdi

    processing_loop:
        mov dil, sil
        cmp sil, 0
        je exit_ft
        inc rdi
        inc rsi
        jmp processing_loop

    exit_ft:
        ret