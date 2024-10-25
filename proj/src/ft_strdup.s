
; char *_ft_strdup(const char *str_alpha);

; size_t _ft_strlen(const char *s);
; char *_ft_strcpy(char *dest, const char *src);
; void *malloc(size_t size);

bits	64

global	ft_strdup

extern	ft_strlen
extern	ft_strcpy
extern	malloc

section	.text

	ft_strdup:

	error_check:
		push rbp
		mov rbp, rsp
		cmp rdi, 0
		je exit_ft

	start_ft:
		push rdi		; save str_alpha pointer on stack;
		sub rsp, 8
		call ft_strlen
		inc rax
		mov rdi, rax
		call malloc
		cmp rax, 0
		add rsp, 8
		pop rsi
		je exit_ft
		mov rdi, rax
		call ft_strcpy

	exit_ft:
		mov rsp, rbp
		pop rbp
		ret
