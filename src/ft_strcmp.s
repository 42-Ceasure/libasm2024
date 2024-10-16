;int _ft_strcmp(const char *s1, const char *s2);

bits 64

global _ft_strcmp

section .text

    _ft_strcmp:
        xor r8, r8
        mov rax, rdi
        cmp rax, 0
        je  exit_ft
        cmp rsi, 0
        je  exit_ft
    

    char_compare:
        mov r8b, [rdi]
        cmp r8b, [rsi]
        jne str_not_equal
        cmp r8b, 0
        je  exit_ft
        inc rdi
        inc rsi
        jmp char_compare
    
    str_not_equal:
        xor r8, r8
        xor r9, r9
        mov r9b, [rsi]
        sub r8b, r9b
    
    exit_ft:
        xor rax, rax
        mov rax, r8
        ret
