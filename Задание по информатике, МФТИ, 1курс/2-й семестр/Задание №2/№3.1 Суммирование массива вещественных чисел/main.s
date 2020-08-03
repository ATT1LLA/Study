	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.intel_syntax noprefix
	.globl	_summ_array
	.p2align	4, 0x90
_summ_array:                            ## @summ_array
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
	xorps	xmm0, xmm0
	mov	qword ptr [rbp - 8], rdi
	movss	dword ptr [rbp - 12], xmm0
	mov	dword ptr [rbp - 16], 0
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 16], 10
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movsxd	rax, dword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 8]
	movss	xmm0, dword ptr [rcx + 4*rax] ## xmm0 = mem[0],zero,zero,zero
	addss	xmm0, dword ptr [rbp - 12]
	movss	dword ptr [rbp - 12], xmm0
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [rbp - 16]
	add	eax, 1
	mov	dword ptr [rbp - 16], eax
	jmp	LBB0_1
LBB0_4:
	movss	xmm0, dword ptr [rbp - 12] ## xmm0 = mem[0],zero,zero,zero
	pop	rbp
	ret
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp5:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	xorps	xmm0, xmm0
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 8], edi
	mov	qword ptr [rbp - 16], rsi
	movss	dword ptr [rbp - 20], xmm0
	mov	dword ptr [rbp - 24], 0
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 24], 10
	jge	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	lea	rdi, [rip + L_.str]
	mov	rax, qword ptr [rip + _arr@GOTPCREL]
	movsxd	rcx, dword ptr [rbp - 24]
	shl	rcx, 2
	add	rax, rcx
	mov	rsi, rax
	mov	al, 0
	call	_scanf
	mov	dword ptr [rbp - 28], eax ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	mov	eax, dword ptr [rbp - 24]
	add	eax, 1
	mov	dword ptr [rbp - 24], eax
	jmp	LBB1_1
LBB1_4:
	mov	rdi, qword ptr [rip + _arr@GOTPCREL]
	call	_summ_array
	lea	rdi, [rip + L_.str.1]
	movss	dword ptr [rbp - 20], xmm0
	cvtss2sd	xmm0, dword ptr [rbp - 20]
	mov	al, 1
	call	_printf
	xor	ecx, ecx
	mov	dword ptr [rbp - 32], eax ## 4-byte Spill
	mov	eax, ecx
	add	rsp, 32
	pop	rbp
	ret
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%f"

	.comm	_arr,40,4               ## @arr
L_.str.1:                               ## @.str.1
	.asciz	"%f\n"


.subsections_via_symbols
