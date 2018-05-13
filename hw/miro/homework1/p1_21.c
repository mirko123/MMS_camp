// Write a program entab that replaces strings of blanks by the minimum number of tabs
// and blanks to achieve the same spacing. Use the same tab stops as for detab. When
// either a tab or a single blank would suffice to reach a tab stop, which should be
// given preference?

#include <stdio.h>
#include <libc.h>

int main(int argc, char *argv[]) {
    char *str = strdup("1	2	3            4");
    char *newString;
    int len = strlen(str);
    int spacesOnTab = atoi(argv[1]);
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
    
    printf("%s\n", newString);
    return 0;
}










