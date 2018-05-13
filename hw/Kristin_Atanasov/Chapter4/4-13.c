#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int len) {
    char c;

	if (i < len) {
		c = s[i];
		s[i++] = s[len];
		s[len--] = c;
		reverse(s, i, len);
	}
	return;
}

int main(void){

    char s[] = "-123456789";
    reverse(s, 0, (int)strlen(s) - 1);
    printf("s reversed = %s", s);

    return 0;
}
