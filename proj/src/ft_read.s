
; ssize_t _ft_read(int fd, void buf[.count], size_t count);

bits	64

global	ft_read
extern	__errno_location

section	.text

	ft_read:
		push rbp
		mov rbp, rsp

	start_ft:
		mov rax, 0
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
		call __errno_location WRT ..plt
		mov [rax], r12
		mov rax, -1
		jmp exit_ft
