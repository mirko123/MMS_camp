// Rewrite the program cat from Chapter 7 using read, write, open, 
// and close instead of their standard library equivalents. Perform 
// experiments to determine the relative speeds of the two versions.
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	char *fileName;
	char val;
	int fd;
	int readed;
	if(argc >= 2) {
		fileName = argv[1];
	}
	fd = open(fileName, O_RDWR);

	if(fd < 0) {
		printf("Porlbme\n");
		return 0;
	}

	while((readed = read(fd, &val, sizeof (val)))) {
		printf("%c",val);
	}


	return 0;
}

