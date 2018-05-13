#ifndef _P2_H_
#define _P2_H_

void clear(unsigned char *c, int N);

int get(const unsigned char *c, int N, int bit);
int set(unsigned char *c, int N, int bit, int boolean);

int getpix(const unsigned char* c, int M, int N, int X, int Y);
int setpix(unsigned char* c, int M, int N, int X, int Y, int colour);

void display(const unsigned char *, int M, int N);

#endif


