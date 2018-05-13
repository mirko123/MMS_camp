

typedef enum {black, white } colour;



void display(const unsigned char *matrix, int M, int N);
int getpix( const unsigned char *matrix, int M, int N, int X, int Y);
int setpix(unsigned char *matrix, int M, int N, int X, int Y, int colour);

