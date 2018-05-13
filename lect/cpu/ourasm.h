#ifndef _OURASM_
#define _OURASM_

/* Turing complete instructions set, minimal RISC load/store architecture */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <sys/types.h>
#include <setjmp.h>

/*
	accumulators: AX, BX, CX, DX, EX, FX, GX, HX
	stack pointer: SP
	base pointer / index register: BP, TP
	index registers: SI, DI, TI
	return address register: RA
	halt register: HLT
*/
typedef jmp_buf retreg_t;
typedef struct registers_t {
	int AX;
	int BX;
	int CX;
	int DX;
	int EX;
	int FX;
	int GX;
	int HX;
	int SP;
	int BP;
	int TP;
	int SI;
	int DI;
	int TI;
	retreg_t RA;
	retreg_t HLT;
} registers_t;

/* access register */
#define REG(_REG_P, _REG_NAME) ((_REG_P)->_REG_NAME)

/* dump registers */
#define PRINT_REGS(_REG_P) \
	do { \
		printf( \
			"AX = %0.8x, BX = %0.8x, CX = %0.8x, DX = %0.8x,\n" \
			"EX = %0.8x, FX = %0.8x, GX = %0.8x, HX = %0.8x,\n" \
			"SI = %0.8x, DI = %0.8x, TI = %0.8x,\n" \
			"BP = %0.8x, TP = %0.8x, SP = %0.8x\n", \
			REG(_REG_P, AX), REG(_REG_P, BX), REG(_REG_P, CX), REG(_REG_P, DX), \
			REG(_REG_P, EX), REG(_REG_P, FX), REG(_REG_P, GX), REG(_REG_P, HX), \
			REG(_REG_P, SI), REG(_REG_P, DI), REG(_REG_P, TI), \
			REG(_REG_P, BP), REG(_REG_P, TP), REG(_REG_P, SP)); \
	} while (0)

/* unconditional jump */
#define JUMP(_LABEL) goto _LABEL

/* jump if equal */
#define JE(A, B, _LABEL) if ((A) == (B)) goto _LABEL

/* jump if not equal */
#define JNE(A, B, _LABEL) if ((A) != (B)) goto _LABEL

/* jump if greater than */
#define JG(A, B, _LABEL) if ((A) > (B)) goto _LABEL

/* jump if less than */
#define JL(A, B, _LABEL) if ((A) < (B)) goto _LABEL

/* jump if greater than or equal */
#define JGE(A, B, _LABEL) if ((A) >= (B)) goto _LABEL

/* jump if less than or equal */
#define JLE(A, B, _LABEL) if ((A) <= (B)) goto _LABEL

/* call subroutine */
#define CALL(_REG_P, _SUB) \
	do { \
		if (setjmp(REG(_REG_P, RA)) != -1) goto _SUB; \
		else (void)memset(REG(_REG_P, RA), sizeof (REG(_REG_P, RA)), 0); \
	} while (0)

/* return from subroutine */
#define RET(_REG_P) \
	do { \
		longjmp(REG(_REG_P, RA), -1); \
	} while (0)

/* init halt vector and start the CPU */
#define PREP_HALT_RUN_CPU(_REG_P, _FUNCTION, _MEM, _MEM_SIZE) \
	do { \
		if (setjmp(REG(_REG_P, HLT)) != -1) (_FUNCTION)(_REG_P, _MEM, _MEM_SIZE); \
		else (void)memset(REG(_REG_P, HLT), sizeof (REG(_REG_P, HLT)), 0); \
	} while (0)

/* halt the CPU */
#define HALT(_REG_P) \
	do { \
		longjmp(REG(_REG_P, HLT), -1); \
	} while (0)

/* load from memory[absolute address in register + direct offset] into register */
#define LD(_MEM, _REG_P, _TYPE, _DST_REG, _SRC_OFF_REG, _OFFSET) \
	do { \
		(void)memset(&REG(_REG_P, _DST_REG), 0, sizeof (REG(_REG_P, _DST_REG))); \
		(void)memcpy(&REG(_REG_P, _DST_REG), (char *)(_MEM) + REG(_REG_P, _SRC_OFF_REG) + (_OFFSET), sizeof (_TYPE)); \
	} while (0)

/* store from register into memory[absolute address in register + direct offset] */
#define ST(_MEM, _REG_P, _TYPE, _SRC_REG, _DST_OFF_REG, _OFFSET) \
	do { \
		(void)memcpy((char *)(_MEM) + REG(_REG_P, _DST_OFF_REG) + (_OFFSET), &REG(_REG_P, _SRC_REG), sizeof (_TYPE)); \
	} while (0)

/* push register onto the stack */
#define PUSHREG(_MEM, _REG_P, _TYPE, _SRC_REG) \
	do { \
		REG(_REG_P, SP) -= sizeof (_TYPE); \
		(void)memcpy((char *)(_MEM) + REG(_REG_P, SP), &REG(_REG_P, _SRC_REG), sizeof (_TYPE)); \
	} while (0)

/* pop from stack into register */
#define POPREG(_MEM, _REG_P, _TYPE, _DST_REG) \
	do { \
		(void)memset(&REG(_REG_P, _DST_REG), 0, sizeof (REG(_REG_P, _DST_REG))); \
		(void)memcpy(&REG(_REG_P, _DST_REG), (char *)(_MEM) + REG(_REG_P, SP), sizeof (_TYPE)); \
		REG(_REG_P, SP) += sizeof (REG(_REG_P, _DST_REG)); \
	} while (0)

/* plain old sugar */
#define BEGIN_ASM do
#define END_ASM while (0)

typedef void (*ourcpu_t)(registers_t *regs, void *mem, size_t mem_zise);

#endif

