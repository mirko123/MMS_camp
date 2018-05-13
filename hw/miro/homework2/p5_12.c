#include <stdio.h>
#include <libc.h>
char* detab(char *str, int spacesOnTab);
char* entab(char *str, int tabsOnSpace);

int main(int argc, char *argv[]) {
	char *str = strdup("das   asd asd asd   	 dsa 	 a 			d a 		");
	char *newString;
	int spacesOnTab = 4;
	int tabsOnSpace = 4;

	if(argc >= 2) {
		if(*(argv[1]) == '-') {
			spacesOnTab = atoi(*(argv[1] + 1));
		}
		else {
			tabsOnSpace = atoi(*(argv[1] + 1));
		}
	}
	if(argc == 3) {
		if(*(argv[2]) == '-') {
			spacesOnTab = atoi(*(argv[2] + 1));
		}
		else {
			tabsOnSpace = atoi(*(argv[2] + 1));
		}
	}


	printf("%s\n", str);
	newString = detab(str,spacesOnTab);
	printf("%s\n", newString);
	newString = entab(str,tabsOnSpace);
	printf("%s\n", newString);
	return 0;
}

char* detab(char *str, int spacesOnTab) {
	char *newString;
	int len = strlen(str);
	newString = (char*)malloc(len*spacesOnTab*sizeof(char));
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
	return newString;
}



char* entab(char *str, int spacesOnTab) {
    char *newString;
    int len = strlen(str);
    int i;
    int j;
    int spaceCounter = 0;
    int countToReplace = 0;
    newString = (char*)malloc(len*sizeof(char));
    
    
    for (i = 0, j = 0; i < len; i++)
    {
        spaceCounter = 0;
        while(i < len && str[i] == ' ') {
            spaceCounter++;
            i++;
        }
        countToReplace = spaceCounter/spacesOnTab;
        if(countToReplace)
            memset(newString + j, '\t', countToReplace);
        if(spaceCounter - countToReplace*spacesOnTab)
            memset(newString + j + countToReplace, ' ', spaceCounter - countToReplace*spacesOnTab);
        j+= spaceCounter - countToReplace*spacesOnTab + countToReplace;
        newString[j] = str[i];
        j++;
        
    }
    
    return newString;
}







