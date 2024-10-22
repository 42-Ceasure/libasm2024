;Entiers de 64 bits : rdi, rsi, rdx, rcx, r8, r9

;Registres sauvegardés par l'appelé
;rbx, rbp, rsp, r12, r13, r14, r15

;Registres sauvegardés par l'appelant
;rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11

bits 64

global _start
extern _ft_strlen
extern _ft_strcpy
extern _ft_write

extern printf

section .data

    message db "ThisIsATest", 10
    formatprintf db "%d", 10, 0

section .text

    _start:
        sub rsp, 8

        mov rdi, message
        call _ft_strlen
        mov r8, rax

        add rsp, 8
    
    print_number:
        sub rsp, 8

        mov rdi, formatprintf
        mov rsi, r8
        xor rax, rax
        call printf

        add rsp, 8

        add r8, 1
    print_msg:
        mov rax, 1
        mov rdi, 1
        mov rsi, message
        mov rdx, r8
        call _ft_write

    exit:
        mov rax, 60
        mov rdi, 1
        syscall
