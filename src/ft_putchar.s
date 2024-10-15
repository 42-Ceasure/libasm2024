bits 64
	
global	_ft_putchar
extern  _ft_write

section	.text

_ft_putchar:
	push rdi
	mov rdi, 1
	mov rsi, rsp
	mov rdx, 1
	call _ft_write
	cmp rax, -1
    je error

exit:	
	pop rdi
    xor rax, rax
	ret

error:
	mov rax, -1
	ret