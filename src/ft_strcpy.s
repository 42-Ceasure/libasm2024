;Entiers de 64 bits : rdi, rsi, rdx, rcx, r8, r9

;Registres sauvegardés par l'appelé
;rbx, rbp, rsp, r12, r13, r14, r15

;Registres sauvegardés par l'appelant
;rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11



;char *_ft_strcpy(char *dest, const char *src);

bits 64

global _ft_strcpy

section .text

    _ft_strcpy:
        mov rax, rdi        ; as we just return pointer on dest,
                            ; setting return value to adress

    processing_loop:
        mov r8b, [rsi]      ; save src char
        mov [rdi], r8b      ; set dest char
        cmp r8b, 0          ; check for end
        je  exit_ft         ; if end, go to exit
        inc rsi             ; increment pointer on src to next char
        inc rdi             ; increment pointer on dest to next char
        jmp processing_loop ; go to processing_loop

    exit_ft:
        ret                 ; as return value is set from start, just leave
