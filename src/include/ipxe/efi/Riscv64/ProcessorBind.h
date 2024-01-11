#ifndef __PROCESSOR_BIND_H__
#define __PROCESSOR_BIND_H__

FILE_LICENCE ( BSD2_PATENT );

//
// Define the processor type so other code can make processor based choices
//
#define MDE_CPU_RISCV64

#define EFIAPI

//
// Make sure we are using the correct packing rules per EFI specification
//
#ifndef __GNUC__
  #pragma pack()
#endif

typedef unsigned long long  UINT64;
typedef long long	    INT64;
typedef unsigned int	    UINT32;
typedef int		    INT32;
typedef unsigned short	    UINT16;
typedef unsigned short	    CHAR16;
typedef short		    INT16;
typedef unsigned char	    BOOLEAN;
typedef unsigned char	    UINT8;
typedef char		    CHAR8;
typedef char		    INT8;
typedef unsigned long long  UINTN;
typedef long long	    INTN;

//
// Processor specific defines
//

//
// A value of native width with the highest bit set.
//
#define MAX_BIT  0x8000000000000000ULL
//
// A value of native width with the two highest bits set.
//
#define MAX_2_BITS  0xC000000000000000ULL

//
// Maximum legal 64-bit address
//
#define MAX_ADDRESS  0xFFFFFFFFFFFFFFFFULL

//
// Maximum usable address at boot time (48 bits using 4KB pages)
//
#define MAX_ALLOC_ADDRESS  0xFFFFFFFFFFFFULL

//
// Maximum legal 64-bit INTN and UINTN values.
//
#define MAX_INTN   ((INTN)0x7FFFFFFFFFFFFFFFULL)
#define MAX_UINTN  ((UINTN)0xFFFFFFFFFFFFFFFFULL)

//
// Page allocation granularity
//
#define DEFAULT_PAGE_ALLOCATION_GRANULARITY  (0x1000)
#define RUNTIME_PAGE_ALLOCATION_GRANULARITY  (0x1000)

#if defined (__GNUC__)
//
// For GNU assembly code, .global or .globl can declare global symbols.
// Define this macro to unify the usage.
//
#define ASM_GLOBAL  .globl
#endif

//
// Required stack alignment
//
#define CPU_STACK_ALIGNMENT  16

/**
  Return the pointer to the first instruction of a function given a function pointer.
  On LOONGARCH CPU architectures, these two pointer values are the same,
  so the implementation of this macro is very simple.

  @param  FunctionPointer   A pointer to a function.

  @return The pointer to the first instruction of a function given a function pointer.

**/
#define FUNCTION_ENTRY_POINT(FunctionPointer)  (VOID *)(UINTN)(FunctionPointer)

#ifndef __USER_LABEL_PREFIX__
#define __USER_LABEL_PREFIX__
#endif

#endif
