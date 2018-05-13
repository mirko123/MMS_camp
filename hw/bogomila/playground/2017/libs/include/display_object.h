#ifndef _DISPLAY_OBJECT_
#define _DISPLAY_OBJECT_

void *display_create(unsigned int *, int, int);
void display_destroy(void *);
void display_setpix(void *, int, int, unsigned int);
unsigned int display_getpix(void *, int, int);
void display_brez_line(void *, int, int, int, int, unsigned int);
void display_brez_c(void *, int, int, int, unsigned int);

#endif 
