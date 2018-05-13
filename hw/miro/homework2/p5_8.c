 // There is no error checking in day_of_year or month_day. Remedy this defect.
#include <stdio.h>
#include <libc.h>
#include <string.h>

/* day_of_year: set day of year from month & day */ 
int isValid(int year, int month, int day) {
	if(month < 1 || 12 < month ||
		day < 1 || 31 < day ||
		year < 1) {
		return 0;
	}
	return 1;
}
int day_of_year(int year, int month, int day) {
	int i, leap;
	if(!isValid(year,month,day))
		return -1;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
	for (i = 1; i < month; i++)
		day += daytab[leap][i]; 
	return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;
	if(!isValid(year,month,day))
		return -1;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i]; 
	*pmonth = i;
	*pday = yearday;
}

int main(int argc, char* argv[]) {
	char *first = strdup("test me");
	char *second = strdup("1111 11");

	return 0;
}