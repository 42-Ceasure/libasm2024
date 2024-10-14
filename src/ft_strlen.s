bits 64

global _ft_strlen

section .text

    _ft_strlen:
        xor rcx, rcx
        cmp rdi, rcx
        je exit_ft

    processing_loop:
        mov r8, [rdi]
        inc rdi
        inc rcx
        cmp r8, 0
        jne processing_loop

    exit_ft:
        mov rax, rcx
        ret
