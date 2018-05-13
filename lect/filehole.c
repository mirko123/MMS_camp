#include <stdio.h>
#include <errno.h>

int main(void) {
	FILE *f;
	unsigned int t = 0xffffffffu;
	
	f = fopen("hole", "w");
	if(!f) {
		perror("fopen");
		goto bad0;
	}
	
	if (fseek(f, 10000000L, SEEK_END) < 0) {
		perror("fseek");
		goto bad1;
	}
	
	if (fwrite(&t, sizeof (t), 1, f) < 0) {
		perror("fwrite");
		goto bad1;
	}
	
	if (fseek(f, -5000000L, SEEK_CUR) < 0) {
		perror("fseek");
		goto bad1;
	}
	
	printf("%ld\n", ftell(f));
	
	fclose(f);
	return 0;
bad1:
	fclose(f);
bad0:
	return 1;
}
