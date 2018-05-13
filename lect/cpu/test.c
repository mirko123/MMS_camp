#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <sys/types.h>

#include "ourasm.h"

void cpurun(registers_t *regs, void *mem, size_t mem_size) {
	BEGIN_ASM {
_R_INIT:
/* SETUP STACK */
		REG(regs, SP) = mem_size;
		
		REG(regs, AX) = 100;
		PUSHREG(mem, regs, int, AX);
		REG(regs, AX) = 1;
		PUSHREG(mem, regs, int, AX);
		CALL(regs, _F_main);
		
		REG(regs, DX) = REG(regs, AX);
		REG(regs, BX) = REG(regs, AX);
		
		CALL(regs, _F_LEBE16);
		REG(regs, CX) = REG(regs, AX);
		
		REG(regs, AX) = REG(regs, BX);
		CALL(regs, _F_LEBE32);
		REG(regs, BX) = REG(regs, AX);
		
		CALL(regs, _F_main1);
		
		HALT(regs);
		
_F_main1:
/* BEGIN CODE function main1 returning void arguments (void) LEAF */
		PUSHREG(mem, regs, int, AX);
		PUSHREG(mem, regs, int, BX);
		REG(regs, AX) = 0;
		REG(regs, BX) = 0;
_L_st_loop:
		JGE(REG(regs, BX), 512, _L_end_st_loop);
		ST(mem, regs, char, AX, BX, 0);
		REG(regs, AX) += 2;
		REG(regs, BX)++;
		JUMP(_L_st_loop);
_L_end_st_loop:
		POPREG(mem, regs, int, BX);
		POPREG(mem, regs, int, AX);
		RET(regs);
/* END CODE */
_F_end_main1: ;
		
_F_main:
/* PROLOGUE BEGIN function main returning int arguments (int, int) */
		PUSHREG(mem, regs, int, BP);
		REG(regs, BP) = REG(regs, SP) + sizeof (REG(regs, BP));
		PUSHREG(mem, regs, retreg_t, RA);
/* PROLOGUE END */
/* BEGIN CODE */
		PUSHREG(mem, regs, int, BX);
		PUSHREG(mem, regs, int, CX);
		PUSHREG(mem, regs, int, DX);
		
		LD(mem, regs, int, BX, BP, 0);
		LD(mem, regs, int, CX, BP, 0 + sizeof (int));
		
		REG(regs, AX) = 0;
_L_0:
		REG(regs, DX) = REG(regs, BX) & 1;
		JNE(REG(regs, DX), 0, _L_skip);
		CALL(regs, _F_sum);
_L_skip:
		REG(regs, BX)++;
		JLE(REG(regs, BX), REG(regs, CX), _L_0);
		
		POPREG(mem, regs, int, DX);
		POPREG(mem, regs, int, CX);
		POPREG(mem, regs, int, BX);
/* END CODE */
/* EPILOGUE BEGIN function returning int arguments (int, int) */
		POPREG(mem, regs, retreg_t, RA);
		POPREG(mem, regs, int, BP);
		REG(regs, SP) += (sizeof (int) + sizeof (int));
		RET(regs);
/* EPILOGUE END */
_F_end_main: ;
		
_F_sum:
/* BEGIN CODE function sum returning int arguments (int(BX)) LEAF */
		REG(regs, AX) += REG(regs, BX);
		RET(regs);
/* END CODE */
_F_end_sum: ;

_F_LEBE16:
/* BEGIN CODE function LEBE16 returning int arguments (int(AX)) LEAF */
		PUSHREG(mem, regs, int, BX);
		PUSHREG(mem, regs, int, AX);
		REG(regs, AX) = 0;
		LD(mem, regs, char, BX, SP, 0);
		REG(regs, BX) <<= 8;
		REG(regs, AX) |= REG(regs, BX);
		LD(mem, regs, char, BX, SP, 1);
		REG(regs, BX) <<= 0;
		REG(regs, AX) |= REG(regs, BX);
		REG(regs, SP) += sizeof (int);
		POPREG(mem, regs, int, BX);
		RET(regs);
/* END CODE */
_F_end_LEBE16: ;

_F_LEBE32:
/* BEGIN CODE function LEBE32 returning int arguments (int(AX)) LEAF */
		PUSHREG(mem, regs, int, BX);
		PUSHREG(mem, regs, int, AX);
		REG(regs, AX) = 0;
		LD(mem, regs, char, BX, SP, 0);
		REG(regs, BX) <<= 24;
		REG(regs, AX) |= REG(regs, BX);
		LD(mem, regs, char, BX, SP, 1);
		REG(regs, BX) <<= 16;
		REG(regs, AX) |= REG(regs, BX);
		LD(mem, regs, char, BX, SP, 2);
		REG(regs, BX) <<= 8;
		REG(regs, AX) |= REG(regs, BX);
		LD(mem, regs, char, BX, SP, 3);
		REG(regs, BX) <<= 0;
		REG(regs, AX) |= REG(regs, BX);
		REG(regs, SP) += sizeof (int);
		POPREG(mem, regs, int, BX);
		RET(regs);
/* END CODE */
_F_end_LEBE32: ;
		
	} END_ASM;
	return;
}

static void dump(FILE *out, void *buf, size_t len) {
	size_t j;
	
	for (j = 0; j < len; j++)
		fprintf(out,
				"%s0x%.2hhx%s",
				((j % 8) == 0) ? "\t" : "",
				((unsigned char *)buf)[j],
				((j % 8) == 7) ? "\n" : " ");
	fprintf(out, "\n");
	fflush(out);
	return;
}

int main(void) {
	registers_t regs;
	int mem[1024];
	ourcpu_t ourcpu = &cpurun;
	
	(void)memset(&regs, 0, sizeof (regs));
	(void)memset(&mem, 0, sizeof (mem));
	
	printf("\tCPU STARTED\n");
	PREP_HALT_RUN_CPU(&regs, *ourcpu, mem, sizeof (mem));
	printf("\tCPU HALTED\n\n");
	
	printf("\tREGISTERS\n");
	PRINT_REGS(&regs);
	printf("\n\tMEMORY\n");
	dump(stdout, mem, sizeof (mem));
	
	return 0;
}

