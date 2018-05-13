#include <stdio.h>
#include <string.h>

void f(void *, int);
void *cpy(void *_d, const void *_s, size_t len);

typedef void *(*cpy_f)(void *, const void *, size_t);

int main(void) {
	int buf[16], buf1[16];
	cpy_f our_cpy;
	int j;
	
	f(buf, sizeof (buf));
	our_cpy = &cpy;
	(*our_cpy)(buf1, buf, sizeof (buf));
	
	for (j = 0; j < 16; j++)
		printf("%0.8x\n", buf1[j]);
	
	our_cpy = &memcpy;
	(*our_cpy)(buf1, buf, sizeof (buf));
	
	for (j = 0; j < 16; j++)
		printf("%0.8x\n", buf1[j]);
	
	return 0;
}

void f(void *_p, int len) {
	unsigned char *p = (unsigned char *)_p;
	int j;
	
	for (j = 0; j < len; j++)
		*(p + j) = (unsigned int)j & 0xffu;
	
	return;
}

void *cpy(void *_d, const void *_s, size_t len) {
	unsigned char *d = (unsigned char *)_d;
	unsigned char *s = (unsigned char *)_s;
	
	while (len--)
		*(d++) = *(s++);
	
	return d;
}


