;char *_ft_strdup(const char *str_alpha);

;void *malloc(size_t size);
;size_t _ft_strlen(const char *s);
;char *_ft_strcpy(char *dest, const char *src);

bits 64

global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

section .text

    _ft_strdup:
        push rdi        ; save str_alpha pointer on stack;
        xor rax, rax
        cmp rdi, 0
        je exit_ft
        call _ft_strlen
        inc rax
        mov rdi, rax
        call _malloc
        cmp rax, 0
        je exit_ft
        mov rdi, rax
        pop rsi
        call _ft_strcpy

    exit_ft:
        ret
