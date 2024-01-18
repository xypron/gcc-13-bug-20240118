#ifndef _BITS_BYTESWAP_H
#define _BITS_BYTESWAP_H

/** @file
 *
 * Byte-order swapping functions
 *
 */

#include <stdint.h>

FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL );

static inline __attribute__ (( always_inline, const )) uint16_t
__bswap_variable_16 ( uint16_t x ) {
	__asm__ (
		"slli t1, %0, 48\n"
		"slli t2, t1, 8\n"
		"srli t1, t1, 8\n"
		"or t1, t1, t2\n"
		"srli %1, t1, 48\n"
		: "=r" ( x ) : "r" ( x ) );
	return x;
}

static inline __attribute__ (( always_inline )) void
__bswap_16s ( uint16_t *x ) {
	*x = __bswap_variable_16 ( *x );
}

static inline __attribute__ (( always_inline, const )) uint32_t
__bswap_variable_32 ( uint32_t x ) {
	__asm__ (
		"slli t1, %0, 32\n"
		"srli t2, t1, 48\n"
		"srli t1, t1, 16\n"
		"or t1, t1, t2\n"
		"slli t2, t1, 8\n"
		"srli t1, t1, 8\n"
		"li t3, 0xff00ff\n"
		"and t1, t1, t3\n"
		"slli t3, t3, 8\n"
		"and t2, t2, t3\n"
		"or t1, t1, t2\n"
		"mv %1, t1\n"
		: "=r" ( x ) : "r" ( x ) );
	return x;
}

static inline __attribute__ (( always_inline )) void
__bswap_32s ( uint32_t *x ) {
	*x = __bswap_variable_32 ( *x );
}

static inline __attribute__ (( always_inline, const )) uint64_t
__bswap_variable_64 ( uint64_t x ) {
	__asm__ (
		"mv t1, %0\n"
		"slli t2, t1, 32\n"
		"srli t1, t1, 32\n"
		"or t1, t1, t2\n"
		"slli t2, t1, 16\n"
		"srli t1, t1, 16\n"
		"li t3, 0xffff0000ffff\n"
		"and t1, t1, t3\n"
		"slli t3, t3, 16\n"
		"and t2, t2, t3\n"
		"or t1, t1, t2\n"
		"slli t2, t1, 8\n"
		"srli t1, t1, 8\n"
		"li t3, 0xff00ff00ff00ff\n"
		"and t1, t1, t3\n"
		"slli t3, t3, 8\n"
		"and t2, t2, t3\n"
		"or t1, t1, t2\n"
		"mv %1, t1\n"
		: "=r" ( x ) : "r" ( x ) );
	return x;
}

static inline __attribute__ (( always_inline )) void
__bswap_64s ( uint64_t *x ) {
	*x = __bswap_variable_64 ( *x );
}

#endif
