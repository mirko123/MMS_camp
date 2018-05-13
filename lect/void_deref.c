#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <inttypes.h>

void *get_dereference(void *mem, size_t size, size_t N) {
	return (void *)((uint8_t *)mem + N * size);
}

void *set_dereference(void *mem, size_t size, size_t N, const void *val) {
	return memcpy(get_dereference(mem, size, N), val, size);
}

int main(void) {
	int t[16], j;
	
	for (j = 0; j < 16; j++)
		(void)set_dereference(t, sizeof (t[0]), j, &j);
	
	for (j = 0; j < 16; j++)
		printf("%d\n", t[j]);
	
	return 0;
}

