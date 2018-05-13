/* cc pwm.c -lrt -o pwm */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sched.h>
#include <time.h>

const char *gpio32 = "/sys/class/gpio/gpio32/value";
static int fd32;

#define _ON_DUTY 2000
#define _OFF_DUTY 0
#define STEP 50
#define FREQ 50u

void set_gpio(int fd, int _val) {
	char val = _val ? '1' : '0';
	
	(void)write(fd, &val, 1);
	(void)lseek(fd, 0, SEEK_SET);
	return;
}

int main(int argc, char *argv[]) {
	struct sched_param p;
	struct timespec t;
	unsigned int i;
	int j, sign;
	int ON_DUTY = _ON_DUTY, OFF_DUTY = _OFF_DUTY;
	
	p.sched_priority = sched_get_priority_max(SCHED_RR);
	if (sched_setscheduler(0, SCHED_RR, &p) < 0)
		perror("sched_setscheduler");
	
	if ((fd32 = open(gpio32, O_RDWR)) < 0) {
		perror("open");
		exit(errno);
	}
	
	t.tv_sec = 0;	
	
	for (i = 0u, j = 0, sign = 1; ; i++) {
		if (j) {
			set_gpio(fd32, j);
			t.tv_nsec = ON_DUTY * 1000;
			nanosleep(&t, NULL);
		} else {
			set_gpio(fd32, j);
			t.tv_nsec = OFF_DUTY * 1000;
			nanosleep(&t, NULL);
		}
		j = !j;
		if (!(i % FREQ)) {
			ON_DUTY += ((-sign) * STEP);
			OFF_DUTY += (sign * STEP);
			if (ON_DUTY < 0) {
				ON_DUTY = _OFF_DUTY;
				OFF_DUTY = _ON_DUTY;
				sign = -sign;
			} else if (OFF_DUTY < 0) {
				ON_DUTY = _ON_DUTY;
				OFF_DUTY = _OFF_DUTY;
				sign = -sign;
			}
		}
	}
	
	set_gpio(fd32, 0);
	close(fd32);
	
	return 0;
}

