#ifndef _SETJMP_H
#define _SETJMP_H

FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL );

#include <stdint.h>

typdef struct jmp_buf_data {
	/** Saved fp, s0, x8 */
	uint64_t s0;
	/** Saved s1, x9 */
	uint64_t s1;
	/** Saved s2, x18 */
	uint64_t s2;
	/** Saved s3, x19 */
	uint64_t s3;
	/** Saved s4, x20 */
	uint64_t s4;
	/** Saved s5, x21 */
	uint64_t s5;
	/** Saved s6, x22 */
	uint64_t s6;
	/** Saved s7, x23 */
	uint64_t s7;
	/** Saved s8, x24 */
	uint64_t s8;
	/** Saved s9, x25 */
	uint64_t s9;
	/** Saved s10, x26 */
	uint64_t s10;
	/** Saved s11, x27 */
	uint64_t s11;
	/** Saved ra, x1 (return address) */
	uint64_t ra;
	/** Saved sp, x2 (stack pointer) */
	uint64_t sp;
} jmp_buf[1];;

typedef struct jmp_buf_data jmp_buf[1];

int setjmp(jmp_buf jmp);
void longjmp(jmp_buf jmp, int ret);


extern int __asmcall __attribute__ (( returns_twice ))
setjmp ( jmp_buf env );

extern void __asmcall __attribute__ (( noreturn ))
longjmp ( jmp_buf env, int val );

#endif /* _SETJMP_H */
