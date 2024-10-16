;int _ft_strcmp(const char *s1, const char *s2);

bits 64

global _ft_strcmp

section .text

    _ft_strcmp:
        mov rax, rdi
        cmp rax, 0
        je  exit_ft
        cmp rsi, 0
        je  exit_ft
    

    char_compare:
        mov al, [rdi]
        cmp al, [rsi]
        jne str_not_equal
        cmp al, 0
        je  exit_ft
        inc rdi
        inc rsi
        jmp char_compare
    
    str_not_equal:
        sub rax, [rsi]
    
    exit_ft:
        ret
