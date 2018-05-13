

void clear(unsigned char *px, int N);
int get(const unsigned char *px, int N, int bit); /* -1 -> range error */
int set(unsigned char *px, int N, int bit, int boolean); /* -1 -> range error */
