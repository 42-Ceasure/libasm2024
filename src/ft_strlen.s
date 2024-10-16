;size_t ft_strlen(const char *s);

bits 64

global _ft_strlen

section .text

    _ft_strlen:
        xor rcx, rcx

    processing_loop:
        mov r8b, [rdi]
        cmp r8b, 0
        je exit_ft
        inc rdi
        inc rcx
        jmp processing_loop

    exit_ft:
        mov rax, rcx
        ret
