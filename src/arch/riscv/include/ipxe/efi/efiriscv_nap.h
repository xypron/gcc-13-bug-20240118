#ifndef _IPXE_EFIRISCV_NAP_H
#define _IPXE_EFIRISCV_NAP_H

/** @file
 *
 * EFI CPU sleeping
 *
 */

FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL );

#ifdef NAP_EFIRISCV
#define NAP_PREFIX_efiriscv
#else
#define NAP_PREFIX_efiriscv __efiriscv_
#endif

#endif /* _IPXE_EFIRISCV_NAP_H */
