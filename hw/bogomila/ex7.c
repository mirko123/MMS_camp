#include <stdio.h>
#include<stdlib.h>
#include <string.h>

enum {
	LEN = 16
};

#if 0

int main (void) {
	char buf[LEN];
	char *p;
	int j;
	
	p = strcpy(buf, "asdfg");
	printf("%p %s\n", p, buf);

	for (j = 0; j < LEN; j++) {
		buf[j] = 0xff;
	}

	p = strncpy(buf, "asdfgaaaaaaaaaaaaaaaaaaa", (sizeof(buf) / sizeof(buf[0])));
	buf[LEN -1] = '\0'; vajno kogato sorsa e po golqm ot destinaciqta
	printf("%p %s\n", p, buf);
	
	for (j = 0; j < LEN; j++) {
		printf("%x \n", (unsigned int)buf[j]);
	}
	
	return 0;
}



int main (void) {  //leksikografska naredba
	char buf[LEN];
	char *p;
	int j;

	char *words[] = { "1", "3", "2", "5", "4", "6", "7", "9", "8", "8", "10", "11", "13", "12", NULL};
		
	for (j = 0;words[j]; j++) {
		if(words[j + 1]) printf("%s %s %d\n", words[j], words[j + 1], strcmp(words[j], words[j + 1]));
	
	}



	return 0;
}


int cmp(const void* _p1, const void* _p2); //zad3

int main (void) { 

     int j;
     char *words[14] = { "b", "abb", "fgt", "ffg", "abs", "aabba", "ghta", "jkdd", "bbc", "re", "1zxcv", "mnbv", "hghf", "aa"};    

     for( j = 0; j<14;j++)
          printf("%s",words[j]); 
      printf("\n");//fputc('\n'stdout);

     qsort(words, sizeof (words) / sizeof (words[0]), sizeof (words[0]), &cmp);// shte sortira na syshtoto mqsto leksikografski
  

 return 0;
}

int cmp(const void* _p1, const void* _p2) { //moje da se kazva po drug nachin, zashtoto gore q podavane po adress, vajno e broqt         argumnti da e edin i syshti 
     printf("cmp called - %s %s\n", *(const char**)_p1, *(const char**)_p2 );// bez kastvane nqma da raboti!!!!!
 return strcmp( *(const char**)_p1, *(const char**)_p2 );// -strcmp obryshta naredbata
}////poluchavame pointer kym pointer

#endif

void f( void *, int );

int main(void) {
     int buf[LEN];
     int j;

     f(buf, sizeof (buf) );

     for (j = 0; j < LEN; j++)
         printf("%x\n", buf[j]);

    return 0;
}

void f( void *_p, int len) {
    unsigned char *p = (unsigned char *)_p;// ne moje da manipolirame directno s void* 
    int j;

    for (j = 0; j < len; j++)
        *(p + j) = (unsigned int)j & 0xffu;// na p+j baita na pred slagame dolnite osem bita na j????????????????????                        

   return;
}
















