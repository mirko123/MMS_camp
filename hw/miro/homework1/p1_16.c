 // Revise the main routine of the longest-line program so it will correctly 
 // print the length of arbitrary long input lines, and as much as possible of the text. 

#include <stdio.h>
#include <libc.h>

int main(void) {
	char **lines;
	char *line;
	char *maxLine;
	int size;
	int currentLentgh;
	int maxLength;
	int i;
	printf("size: ");
	scanf("%d",&size);
	size++;

	for (i = 0; i < size; ++i)
	{
		line = calloc(60,sizeof(char));
		fgets(line,60,stdin);
		lines[i] = line;
	}

	currentLentgh = maxLength = 0;
	for (i = 0; i < size; ++i)
	{
		currentLentgh = strlen(lines[i]);
		if(currentLentgh > maxLength) {
			maxLength = currentLentgh;
			maxLine = lines[i];
		}
	}

	printf("%s\n", maxLine);
	return 0;
}










