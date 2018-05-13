#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd;
	int buf[4] = { -1, 0, -2, -3 };
	int t;
	ssize_t s;
	
	fd = open("fd_file", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	printf("fd = %d\n", fd);
	s = write(fd, buf, sizeof (buf));
	printf("write = %ld\n", s);
	s = lseek(fd, 0, SEEK_SET);
	printf("lseek = %ld\n", s);
	s = read(fd, &t, sizeof (t));
	printf("read = %ld, t = %d\n", s, t);
	close(fd);
	return 0;
}
