	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.intel_syntax noprefix
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp2:
	.cfi_def_cfa_register rbp
	sub	rsp, 80
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	dword ptr [rbp - 52], 0
	mov	dword ptr [rbp - 56], edi
	mov	qword ptr [rbp - 64], rsi
	mov	dword ptr [rbp - 68], 0
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 68], 10
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [rbp - 68]
	movsxd	rcx, dword ptr [rbp - 68]
	mov	dword ptr [rbp + 4*rcx - 48], eax
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [rbp - 68]
	add	eax, 1
	mov	dword ptr [rbp - 68], eax
	jmp	LBB0_1
LBB0_4:
	mov	dword ptr [rbp - 68], 0
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 68], 10
	jge	LBB0_7
## BB#6:                                ##   in Loop: Header=BB0_5 Depth=1
	mov	eax, dword ptr [rbp - 68]
	movsxd	rcx, dword ptr [rbp - 68]
	mov	dword ptr [rbp + 4*rcx - 48], eax
	mov	eax, dword ptr [rbp - 68]
	add	eax, 1
	mov	dword ptr [rbp - 68], eax
	jmp	LBB0_5
LBB0_7:
	mov	dword ptr [rbp - 68], 0
LBB0_8:                                 ## =>This Inner Loop Header: Depth=1
	mov	eax, dword ptr [rbp - 68]
	movsxd	rcx, dword ptr [rbp - 68]
	mov	dword ptr [rbp + 4*rcx - 48], eax
	mov	eax, dword ptr [rbp - 68]
	add	eax, 1
	mov	dword ptr [rbp - 68], eax
## BB#9:                                ##   in Loop: Header=BB0_8 Depth=1
	cmp	dword ptr [rbp - 68], 9
	jl	LBB0_8
## BB#10:
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB0_12
## BB#11:
	xor	eax, eax
	add	rsp, 80
	pop	rbp
	ret
LBB0_12:
	call	___stack_chk_fail
	.cfi_endproc


.subsections_via_symbols
