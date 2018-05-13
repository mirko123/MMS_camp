#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

enum {
	MAXLINE = 10,
	MAXSIZE = 128
};

void readZaGencho(char **argv){

	char filename[] = "za_gencho";
	
	printf("test1");
	int line = 0;
	
	FILE *file = fopen (filename, "r");
	
	printf("%d \n", (int)(sizeof **argv));
	
	if (file == NULL){
		perror (filename);
		return;
	}
	else {
		while (fgetc (file) != NULL) {
			fputs(*argv, stdout);
		}
		printf("test4");
	fclose (file);
	}
	printf("test2");

}



int main(void){

	char **argv;
	argv =(char **) malloc(MAXLINE);
	int i;
	
	for(i = 0; i < MAXLINE; ++i){
		*argv = (char *)malloc(MAXSIZE);
	}
	
	
	readZaGencho(argv);
	
	for(i = 0; i < MAXLINE; ++i){
		free(argv[i]);
	}	
	printf("test3");
	free(argv);
	


return 0;
}
