#include <stdio.h>

int main(void) {
	FILE *image;
	int i, t0;
	unsigned char t1;
	
	image = fopen("image", "w");
	if (!image) return 1;
	
#if 0
	t0 = 8;
	fwrite(&t0, sizeof(t0), 1, image);
	fwrite(&t0, sizeof(t0), 1, image);
	
	for (t1 = 1u; t1; t1 <<= 1)
		fwrite(&t1, sizeof(t1), 1, image);
#endif
	t0 = 16;
	fwrite(&t0, sizeof(t0), 1, image);
	fwrite(&t0, sizeof(t0), 1, image);
	
	for (i = 0; i < 2; i++)
		for (t1 = 1u; t1; t1 <<= 1) {
			fwrite(&t1, sizeof(t1), 1, image);
			fwrite(&t1, sizeof(t1), 1, image);
		}
	
	fclose(image);
	return 0;
}

