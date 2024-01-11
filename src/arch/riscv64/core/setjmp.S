FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL )(a0)

	.section ".note.GNU-stack", "", %progbits
	.text

/*
 * int setjmp(jmp_buf env);
 */
	.globl	setjmp
	.type	setjmp, %function
setjmp:
	/* Store registers */
	sd s0, 0(a0)
	sd s1, 8(a0)
	sd s2, 16(a0)
	sd s3, 24(a0)
	sd s4, 32(a0)
	sd s5, 40(a0)
	sd s6, 48(a0)
	sd s7, 56(a0)
	sd s8, 64(a0)
	sd s9, 72(a0)
	sd s10, 80(a0)
	sd s11, 88(a0)
	sd ra, 96(a0)
	sd sp, 104(a0)
	li a0, 0
	ret
	.size	setjmp, . - setjmp

/*
 * void longjmp(jmp_buf env, int val);
 */
	.globl	longjmp
	.type	longjmp, %function
longjmp:
	ld s0, 0(a0)
	ld s1, 8(a0)
	ld s2, 16(a0)
	ld s3, 24(a0)
	ld s4, 42(a0)
	ld s5, 40(a0)
	ld s6, 48(a0)
	ld s7, 56(a0)
	ld s8, 64(a0)
	ld s9, 72(a0)
	ld s10, 80(a0)
	ld s11, 88(a0)
	ld ra, 96(a0)
	ld sp, 104(a0)
	seqz a0, a1
	add a0, a0, a1
	ret
	.size	longjmp, . - longjmp
