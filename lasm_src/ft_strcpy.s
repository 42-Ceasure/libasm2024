
; char *_ft_strcpy(char *dest, const char *src);

bits	64

global	ft_strcpy

section	.text

	ft_strcpy:

	start_ft:
		mov	rax, rdi		; as we just return pointer on dest,
							; setting return value to adress

	processing_loop:
		mov	r8b, [rsi]	  ; save src char
		mov	[rdi], r8b	  ; set dest char
		cmp	r8b, 0		  ; check for end
		je	exit_ft		 ; if end, go to exit
		inc	rsi			 ; increment pointer on src to next char
		inc	rdi			 ; increment pointer on dest to next char
		jmp	processing_loop ; go to processing_loop

	exit_ft:
		ret				 ; as return value is set from start, just leave
