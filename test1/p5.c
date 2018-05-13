#include <stdio.h>
#include <stdlib.h>

#include "p2.h"
#include "p3.h"

int main(void) {
	FILE *image;
	unsigned char *d;
	int M, N;
	int j, bytes;
	
	image = fopen("image", "r");
	if (!image) return 1;
	
	fread(&M, sizeof(M), 1, image);
	fread(&N, sizeof(N), 1, image);
	
	bytes = (M * N) / 8 + !!((M * N) % 8);
	if (bytes < 0) goto bad0;
	
	printf("%d %d %d\n", M, N, bytes);
	
	d = (unsigned char *)malloc(bytes);
	if (!d) goto bad0;
	
	fread(d, sizeof(*d), bytes, image);
	display(d, M, N);
	
	free(d);
bad0:
	fclose(image);
	return 0;
}
