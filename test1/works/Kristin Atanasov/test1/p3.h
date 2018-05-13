#ifndef _P1_H_
#define _P1_H_H
struct pixels{
	int x,
	int y};
typedef struct pixels pixels;
int getpix(const unsigned char *, int M, int N, int X, int Y);
int setpix(const unsigned char *, int M, int N, int X, int Y, int colour);
void display(const unsigned char *, int M, int N);

#endif
