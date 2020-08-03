global main

extern scanf
extern printf

section .text
main:
    push ebp
    mov ebp, esp

    mov eax, '0'
    push eax
;/---------------------------------------------
In1:		                   ; ввод строки
    push input
    push fmt
    call scanf
    add esp, 4
    push input

    cmp dword ptr [esp + 4], 0
    je In2

    jmp In1

In2:
    xor eax, eax
    mov esp, ebp
    pop ebp
    ret
;/---------------------------------------------
Out1:                           ; вывод строки
        mov esp, ebp
    mov ecx, 1
    mov ebx, dword ptr [ebp + 4 * ecx]

    push ebx
    push fmt
    call printf

    add ecx, 1

    cmp byte ptr [ebx], 0
    je Out2

    jmp Out1

Out2:
    xor eax, eax
    mov esp, ebp
    pop ebp
    ret
;/---------------------------------------------

global property

property:
    mov esp, ebp
    mov ecx, 1
p:
    mov ebx, dword ptr [ebp + 4 * ecx]

    cmp byte ptr[ebx], 0
    je p1
    cmp byte ptr[ebx], 'A'
    jb p1
    cmp byte ptr[ebx], 'z'
    ja p1
    cmp byte ptr[ebx], 'Z'
    jbe true
    cmp byte ptr[ebx], 'a'
    jae true
    jmp p1
true:
    add ecx, 1
    jmp p
p1:
    push ecx
    push fmt
    printf

    xor eax, eax
    mov esp, ebp
    pop ebp
    ret

section .data
fmt     db '%c', 0
input   db '0', 0
