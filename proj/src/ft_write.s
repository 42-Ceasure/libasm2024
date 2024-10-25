; Entiers de 64 bits : rdi, rsi, rdx, rcx, r8, r9

; Registres sauvegardés par l'appelé
; rbx, rbp, rsp, r12, r13, r14, r15

; Registres sauvegardés par l'appelant
; rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11


; ssize_t _ft_write(int fd, const void *buf, size_t count);

bits	64

global	ft_write

extern	__errno_location

section	.text

	ft_write:
		push rbp
		mov rbp, rsp

	start_ft:
		mov rax, 1
		syscall
		cmp rax, 0
		jl	error_ft

	exit_ft:
		mov rsp, rbp
		pop rbp
		ret

	error_ft:
		neg rax
		mov r12, rax
		call __errno_location
		mov [rax], r12
		mov rax, -1
		jmp exit_ft
