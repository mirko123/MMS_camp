#include <stdio.h>
#include <sys/types.h>
#include <inttypes.h>

typedef struct {
	uint64_t l64, h64;
} u_128;

static const char hex[] = {
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

static const uint64_t mask[] = {
	1LLU << 0, 1LLU << 1, 1LLU << 2, 1LLU << 3, 1LLU << 4, 1LLU << 5, 1LLU << 6, 1LLU << 7,
	1LLU << 8, 1LLU << 9, 1LLU << 10, 1LLU << 11, 1LLU << 12, 1LLU << 13, 1LLU << 14, 1LLU << 15,
	1LLU << 16, 1LLU << 17, 1LLU << 18, 1LLU << 19, 1LLU << 20, 1LLU << 21, 1LLU << 22, 1LLU << 23,
	1LLU << 24, 1LLU << 25, 1LLU << 26, 1LLU << 27, 1LLU << 28, 1LLU << 29, 1LLU << 30, 1LLU << 31,
	1LLU << 32, 1LLU << 33, 1LLU << 34, 1LLU << 35, 1LLU << 36, 1LLU << 37, 1LLU << 38, 1LLU << 39,
	1LLU << 40, 1LLU << 41, 1LLU << 42, 1LLU << 43, 1LLU << 44, 1LLU << 45, 1LLU << 46, 1LLU << 47,
	1LLU << 48, 1LLU << 49, 1LLU << 50, 1LLU << 51, 1LLU << 52, 1LLU << 53, 1LLU << 54, 1LLU << 55,
	1LLU << 56, 1LLU << 57, 1LLU << 58, 1LLU << 59, 1LLU << 60, 1LLU << 61, 1LLU << 62, 1LLU << 63
};

void mul(uint64_t, uint64_t, u_128 *);
void mul1(uint64_t, uint64_t, u_128 *);
void print64(FILE *, uint64_t);
void print(FILE *, u_128);

void mul(uint64_t a, uint64_t b, u_128 *result) {
	int j;
	uint64_t carry, tmp;
	
	result->h64 = 0;
	result->l64 = (a & mask[0]) ? b : 0;
	
	for (j = 1; j < 64; j++) {
		if(a & mask[j]) {
			tmp = b << j;
			carry = ((0xffffffffffffffffLLU - result->l64) < tmp) ? 1LLU:0LLU;
			result->l64 += tmp;
			tmp = (b & (0xffffffffffffffffLLU << (64 - j))) >> (64 - j);
			result->h64 += tmp + carry;
		}
	}
	
	return;
}

void mul1(uint64_t a, uint64_t b, u_128 *result) {
	uint64_t tmp00, tmp01, tmp10, tmp11, carry;
	
	result->h64 = (a >> 32) * (b >> 32);
	result->l64 = (a & 0x00000000ffffffffLLU) * (b & 0x00000000ffffffffLLU);
	
	tmp00 = (a & 0x00000000ffffffffLLU) * (b >> 32);
	tmp11 = (b & 0x00000000ffffffffLLU) * (a >> 32);
	tmp01 = tmp00 >> 32;
	tmp10 = tmp00 << 32;
	
	carry = ((0xffffffffffffffffLLU - result->l64) < tmp10) ? 1LLU : 0LLU;
	
	result->l64 += tmp10;
	result->h64 += tmp01 + carry;
	
	tmp01 = tmp11 >> 32;
	tmp10 = tmp11 << 32;
	
	carry = ((0xffffffffffffffffLLU - result->l64) < tmp10) ? 1LLU : 0LLU;
	
	result->l64 += tmp10;
	result->h64 += tmp01 + carry;
	
	return;
}

void print64(FILE *f, uint64_t a) {
	uint64_t tmp = 0xf000000000000000LLU;
	int j;
	
	for (j = 0; j < 16; j++) {
		fputc(hex[(a & tmp) >> (64 - (j + 1) * 4)], f);
		tmp = tmp >> 4;
	}
	
	return;
}

void print128(FILE *f, u_128 a) {
	fprintf(f, "0x");
	print64(f, a.h64);
	print64(f, a.l64);
	
	return;
}

int main() {
	uint64_t j, a, b;
	u_128 t;
	
	a = 0xba98fedc32107654LLU;
	for (j = 0xf0000000LLU; j < 0xf000ffffLLU; j++) {
		b = j << 32 | j;
		mul1(a, b, &t);
		fprintf(stdout, "0x");
		print64(stdout, a);
		fputc(' ', stdout);
		fprintf(stdout, "0x");
		print64(stdout, b);
		fputc(' ', stdout);
		print128(stdout, t);
		fputc('\n', stdout);
	}
	
	return 0;
}
