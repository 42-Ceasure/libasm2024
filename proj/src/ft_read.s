
; ssize_t _ft_read(int fd, void buf[.count], size_t count);

bits	64

global	ft_read

section	.text

	ft_read:
		push rbp
		mov rbp, rsp

	start_ft:
		mov	rax, 0
		syscall
		jc	error

	exit_ft:
		mov	rsp, rbp
		pop	rbp
		ret

	error:
		mov	rax, -1
		jmp	exit_ft