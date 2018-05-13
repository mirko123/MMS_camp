#include <stdio.h>
#include <unistd.h>
#include <setjmp.h>

static int cnt = 0;
static jmp_buf jb;

void f0(void);
void f1(void);
void f2(void);
void f3(void);

int main(void) {
	int setjmp_result;
	
	setjmp_result = setjmp(jb);
	printf("setjmp returned %d\n", setjmp_result);
	sleep(1);
	f0();

	return 0;
}

void f0(void) {
	cnt++;
	f1();
	return;
}

void f1(void) {
	cnt++;
	f2();
	return;
}

void f2(void) {
	cnt++;
	f3();
	return;
}

void f3(void) {
	cnt++;
	longjmp(jb, cnt);
	return;
}

