	.file	"tcp_client.c"
	.text
	.section	.rodata
.LC0:
	.string	"127.0.0.1"
.LC1:
	.string	"connect"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket@PLT
	movl	%eax, -4(%rbp)
	movw	$2, -32(%rbp)
	movl	$8080, %edi
	call	htons@PLT
	movw	%ax, -30(%rbp)
	leaq	-32(%rbp), %rax
	addq	$4, %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movl	$2, %edi
	call	inet_pton@PLT
	leaq	-32(%rbp), %rcx
	movl	-4(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect@PLT
	testl	%eax, %eax
	jns	.L2
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L4
.L2:
	movabsq	$8295679370688488776, %rax
	movq	%rax, -47(%rbp)
	movabsq	$9414454335923571, %rax
	movq	%rax, -40(%rbp)
	leaq	-47(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rdx
	leaq	-47(%rbp), %rsi
	movl	-4(%rbp), %eax
	movl	$0, %ecx
	movl	%eax, %edi
	call	send@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	$0, %eax
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Debian 14.2.0-19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
