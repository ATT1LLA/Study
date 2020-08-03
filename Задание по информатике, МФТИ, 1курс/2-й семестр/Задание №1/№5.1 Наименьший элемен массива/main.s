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
	sub	rsp, 48
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 8], edi
	mov	qword ptr [rbp - 16], rsi
	mov	dword ptr [rbp - 20], 0
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 20], 10
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	lea	rdi, [rip + L_.str]
	mov	rax, qword ptr [rip + _arr@GOTPCREL]
	movsxd	rcx, dword ptr [rbp - 20]
	shl	rcx, 2
	add	rax, rcx
	mov	rsi, rax
	mov	al, 0
	call	_scanf
	mov	dword ptr [rbp - 32], eax ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [rbp - 20]
	add	eax, 1
	mov	dword ptr [rbp - 20], eax
	jmp	LBB0_1
LBB0_4:
	mov	rax, qword ptr [rip + _arr@GOTPCREL]
	mov	ecx, dword ptr [rax]
	mov	dword ptr [rbp - 24], ecx
	mov	dword ptr [rbp - 28], 1
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 28], 10
	jge	LBB0_10
## BB#6:                                ##   in Loop: Header=BB0_5 Depth=1
	mov	rax, qword ptr [rip + _arr@GOTPCREL]
	movsxd	rcx, dword ptr [rbp - 28]
	mov	edx, dword ptr [rax + 4*rcx]
	cmp	edx, dword ptr [rbp - 24]
	jge	LBB0_8
## BB#7:                                ##   in Loop: Header=BB0_5 Depth=1
	mov	rax, qword ptr [rip + _arr@GOTPCREL]
	movsxd	rcx, dword ptr [rbp - 28]
	mov	edx, dword ptr [rax + 4*rcx]
	mov	dword ptr [rbp - 24], edx
LBB0_8:                                 ##   in Loop: Header=BB0_5 Depth=1
	jmp	LBB0_9
LBB0_9:                                 ##   in Loop: Header=BB0_5 Depth=1
	mov	eax, dword ptr [rbp - 28]
	add	eax, 1
	mov	dword ptr [rbp - 28], eax
	jmp	LBB0_5
LBB0_10:
	lea	rdi, [rip + L_.str.1]
	mov	esi, dword ptr [rbp - 24]
	mov	al, 0
	call	_printf
	xor	esi, esi
	mov	dword ptr [rbp - 36], eax ## 4-byte Spill
	mov	eax, esi
	add	rsp, 48
	pop	rbp
	ret
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

	.comm	_arr,40,4               ## @arr
L_.str.1:                               ## @.str.1
	.asciz	"%d\n"


.subsections_via_symbols
