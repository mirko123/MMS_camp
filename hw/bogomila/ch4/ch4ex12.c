#include<stdio.h>
#include<math.h>

#define MAX 100

void itoa(int, char*);


int main(void)
{
	int n;
	char s[MAX];

	n = 50236;

	itoa(n, s);

	printf("%s", s);

	return 0;
}

void itoa(int n, char s[])
{
	int i;

	if (n / 10) itoa(n / 10, s);
	else
	{
		i = 0;
		if (n < 0) {
			s[i] = '-';
			i++;
		}
	}

	s[i] = abs(n) % 10 + '0';
	i++;

	s[i] = '\0';

}