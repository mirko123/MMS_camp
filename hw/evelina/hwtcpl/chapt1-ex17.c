#include <stdio.h>

int getline(char s[], int l)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < l-2)
			s[j++] = c;
	if (c == '\n')
	{
		s[j++] = c;
		++i;
	}
	s[j] = '\0';

	return i;
}

int main()
{
	int len;               
	char line[1000];

	while ((len = getline(line, 1000)) > 0)
		if (len > 80)
			printf("%s", line);

	return 0;
}

