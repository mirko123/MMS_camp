// Write a program to determine the ranges of char, short, int, and long 
// variables, both signed and unsigned, by printing appropriate values 
// from standard headers and by direct computation. Harder if you compute 
// them: determine the ranges of the various floating-point types.
#include <stdio.h>
#include <libc.h>

int main(void) {
	char c = 127;
	short s = 0;
	int i = 0;
	long l = 0;

	unsigned char uc = 0;
	unsigned short us = 0;
	unsigned int ui = 0;
	unsigned long ul = 0;

	long counter;

	c = 0;
	while(c < (char)(c+1)) {
		c++;
	}
	printf("max c: %d\n", c);

	c = 0;
	while(c > (char)(c-1)) c--;
	printf("min c: %d\n", c);


	uc = 0;
	while(uc < (unsigned char)(uc+1)) uc++;
	printf("max c: %du\n", uc);

	uc = 0;
	while(uc > (unsigned char)(uc-1)) uc--;
	printf("min c: %du\n", uc);



	s = 0;
	while(s < (short)(s+1)) {
		s++;
	}
	printf("max s: %d\n", s);

	s = 0;
	while(s > (char)(s-1)) s--;
	printf("min s: %d\n", s);


	us = 0;
	while(us < (unsigned short)(us+1)) {
		us++;
	}
	printf("max us: %du\n", us);

	us = 0;
	while(us > (unsigned short)(us-1)) us--;
	printf("min us: %du\n", us);




	i = 0;
	while(i < (int)(i+1)) {
		i++;
	}
	printf("max i: %d\n", i);

	i = 0;
	while(i > (int)(i-1)) i--;
	printf("min i: %d\n", i);


	ui = 0;
	while(ui < (unsigned int)(ui+1)) {
		ui++;
	}
	printf("max ui: %du\n", ui);

	ui = 0;
	while(ui > (unsigned int)(ui-1)) ui--;
	printf("min ui: %du\n", ui);



	l = 0;
	while(l < (long)(l+1)) {
		l++;
	}
	printf("max l: %ld\n", l);

	l = 0;
	while(l > (long)(l-1)) l--;
	printf("min l: %ld\n", l);


	ul = 0;
	while(ul < (unsigned long)(ul+1)) {
		ul++;
	}
	printf("max ul: %lu\n", ul);

	ul = 0;
	while(ul > (unsigned long)(ul-1)) ul--;
	printf("min ul: %lu\n", ul);

	return 0;
}










