#ifndef _P1_H_
#define _P1_H_H

void clear(unsigned int *, int N);
int get(const unsigned int *, int N, int bit); /*-1 -> range error */
int set(unsigned int *, int N, int bit, int boolean); /*-1 -> range error*/

#endif
