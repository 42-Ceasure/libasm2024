
; char *_ft_strdup(const char *str_alpha);

; size_t _ft_strlen(const char *s);
; char *_ft_strcpy(char *dest, const char *src);
; void *malloc(size_t size);

bits	64

global	_ft_strdup

extern	_ft_strlen
extern	_ft_strcpy
extern	malloc

section	.text

	_ft_strdup:

	error_check:
		push rbp
		mov rbp, rsp
		cmp rdi, 0
		je exit_ft

	start_ft:
		push rdi		; save str_alpha pointer on stack;
		call _ft_strlen
		inc rax
		mov rdi, rax
		call malloc
		cmp rax, 0
		je exit_ft
		mov rdi, rax
		pop rsi
		call _ft_strcpy

	exit_ft:
		mov rsp, rbp
		pop rbp
		ret
