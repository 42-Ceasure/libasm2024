
; size_t _ft_strlen(const char *str);

bits	64

global	_ft_strlen

section	.text

	_ft_strlen:
		
	error_check:
		cmp rdi,  0			; check valid
		je  exit_ft			; if not, go to exit

	start_ft:
		xor rcx, rcx		; reset rcx (counter for len)
		
	processing_loop:
		mov r8b, [rdi]		; save last byte of rdi
		cmp r8b, 0			; check if end of str
		je  exit_ft			; if end, go to exit
		inc rdi				; increment pointer on str to next char
		inc rcx				; increment counter (len)
		jmp processing_loop	; go to processing loop

	exit_ft:
		mov rax, rcx		; set return value to counter (len)
		ret					; return len
