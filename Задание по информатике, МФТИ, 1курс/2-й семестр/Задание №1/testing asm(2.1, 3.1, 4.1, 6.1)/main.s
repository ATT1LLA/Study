	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.intel_syntax noprefix
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI0_0:
	.quad	4607677814759028163     ## double 1.1100000000000001
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2
LCPI0_1:
	.long	1066192077              ## float 1.10000002
	.section	__TEXT,__text,regular,pure_instructions
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
	lea	rax, [rip + L_.str]
	mov	rcx, qword ptr [rip + _a1@GOTPCREL]
	movsd	xmm0, qword ptr [rip + LCPI0_0] ## xmm0 = mem[0],zero
	movss	xmm1, dword ptr [rip + LCPI0_1] ## xmm1 = mem[0],zero,zero,zero
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 8], edi
	mov	qword ptr [rbp - 16], rsi
	mov	dword ptr [rbp - 20], 1
	mov	qword ptr [rbp - 32], 2
	mov	dword ptr [rbp - 36], 3
	mov	qword ptr [rbp - 48], 4
	movss	dword ptr [rbp - 52], xmm1
	movsd	qword ptr [rbp - 64], xmm0
	mov	byte ptr [rbp - 65], 78
	mov	rdi, rax
	mov	rsi, rcx
	mov	al, 0
	call	_scanf
	mov	rcx, qword ptr [rip + _a1@GOTPCREL]
	mov	edx, 2
	mov	r8d, dword ptr [rcx]
	add	r8d, 2
	mov	dword ptr [rcx], r8d
	mov	r8d, dword ptr [rcx]
	shl	r8d, 1
	mov	dword ptr [rcx], r8d
	mov	r8d, dword ptr [rcx]
	sub	r8d, 2
	mov	dword ptr [rcx], r8d
	mov	r8d, dword ptr [rcx]
	mov	dword ptr [rbp - 72], eax ## 4-byte Spill
	mov	eax, r8d
	mov	dword ptr [rbp - 76], edx ## 4-byte Spill
	cdq
	mov	r8d, dword ptr [rbp - 76] ## 4-byte Reload
	idiv	r8d
	mov	dword ptr [rcx], eax
	cmp	dword ptr [rcx], 2
	jge	LBB0_2
## BB#1:
	mov	rax, qword ptr [rip + _a2@GOTPCREL]
	mov	qword ptr [rax], -1
	jmp	LBB0_6
LBB0_2:
	mov	rax, qword ptr [rip + _a1@GOTPCREL]
	cmp	dword ptr [rax], 2
	jle	LBB0_4
## BB#3:
	mov	rax, qword ptr [rip + _a2@GOTPCREL]
	mov	qword ptr [rax], 1
	jmp	LBB0_5
LBB0_4:
	mov	rax, qword ptr [rip + _a2@GOTPCREL]
	mov	qword ptr [rax], 0
LBB0_5:
	jmp	LBB0_6
LBB0_6:
	xor	eax, eax
	add	rsp, 80
	pop	rbp
	ret
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

	.comm	_a1,4,2                 ## @a1
	.comm	_a2,8,3                 ## @a2
	.comm	_a3,4,2                 ## @a3
	.comm	_a4,8,3                 ## @a4
	.comm	_f,4,2                  ## @f
	.comm	_d,8,3                  ## @d
	.comm	_c,1,0                  ## @c

.subsections_via_symbols
