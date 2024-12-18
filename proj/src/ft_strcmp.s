; // Registres sauvegardés par l'appelé
; // rbx, rbp, rsp, r12, r13, r14, r15
; int _ft_strcmp(const char *s1, const char *s2);

bits	64

global	ft_strcmp

section	.text

	ft_strcmp:

	error_check:
		mov	rax, rdi
		cmp	rax, 0
		je	exit_ft
		cmp	rsi, 0
		je	exit_ft

	start_ft:
		xor	rax, rax
		xor	rcx, rcx

	processing_loop:
		mov	al, [rdi]
		cmp	al, [rsi]
		jne	str_not_equal
		cmp	al, 0
		je	exit_ft
		inc	rdi
		inc	rsi
		jmp	processing_loop
		
	str_not_equal:
		mov	cl, [rsi]
		sub	rax, rcx

	exit_ft:
		ret
