bits 64

global _ft_strlen

section .text

    _ft_strlen:
        xor rcx, rcx
        mov rax, 0
        cmp rdi, 0
        je exit_ft
        not rcx
        repne scasb
        not rcx					
        lea rax, [rcx - 1]
            
    exit_ft:
        ret
