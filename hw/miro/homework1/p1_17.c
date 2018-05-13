 // Revise the main routine of the longest-line program so it will correctly 
 // print the length of arbitrary long input lines, and as much as possible of the text. 

#include <stdio.h>
#include <libc.h>

int main(void) {
	char **lines;
	char *line;
	int size;
	int currentLentgh;
	int maxLength = 80;
	int i;
	printf("size: ");
	scanf("%d",&size);
	size++;

	for (i = 0; i < size; ++i)
	{
		line = calloc(256,sizeof(char));
		fgets(line,256,stdin);
		lines[i] = line;
	}

	for (i = 0; i < size; ++i)
	{
		currentLentgh = strlen(lines[i]);
		if(maxLength < currentLentgh) {
			printf("%s\n", lines[i]);
		}
	}

	return 0;
}










