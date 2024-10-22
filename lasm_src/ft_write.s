; Entiers de 64 bits : rdi, rsi, rdx, rcx, r8, r9

; Registres sauvegardés par l'appelé
; rbx, rbp, rsp, r12, r13, r14, r15

; Registres sauvegardés par l'appelant
; rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11


; ssize_t _ft_write(int fd, const void *buf, size_t count);

bits	64

global	ft_write

section	.text

	ft_write:
		mov rax, 1
		syscall
		jc error
		ret

	error:
		mov rax, -1
		ret
