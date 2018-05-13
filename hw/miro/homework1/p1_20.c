// Write a program detab that replaces tabs in the input with the proper number of blanks
// to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. 
// Should n be a variable or a symbolic parameter?  

#include <stdio.h>
#include <libc.h>

int main(int argc, char *argv[]) {
	char *str = strdup("das   asd asd asd   	 dsa 	 a 			d a 		");
	char *newString;
	int len = strlen(str);
	int spacesOnTab = atoi(argv[1]);
	newString = malloc(len*spacesOnTab*sizeof(char));
	char *c;
	int i;
	int j;
	int p;
	for (i = 0, j = 0; i < len; ++i)
	{
		if(str[i] == '\t') {
			for (p = 0; p < spacesOnTab; ++p)
			{
				newString[j+p] = ' ';
			}
			j+=spacesOnTab;
		}
		else {
			newString[j] = str[i];
			j++;
		}
	}
	printf("%s\n", newString);
	return 0;
}










