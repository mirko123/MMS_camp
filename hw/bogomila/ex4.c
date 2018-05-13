#include<stdio.h>
#include<stdlib.h>
#include<math.h>



/*
int main(void) {
    int c;

    while((c = getchar()) != EOF)
         if(putchar(c) == EOF) break;

    return 0;

}


int main(void) {
     FILE* f;

     f=fopen("new_file","w+");
     if(!f) goto out;
     fprintf(f, "we've just created a file\n");
     fclose(f);

out:
    return 0;

}

int main(void) {
     FILE* f;

     f=fopen("new_file","a");
     if(!f) goto out;
     fprintf(f, "and appended a line to file\n");
     fclose(f);

out:
    return 0;

}
int main(void) { //zad1
     FILE* f;
     int c;
     unsigned int mask;

     f=fopen("new_file","r");
     if(!f) goto out;
     while((c = fgetc(f)) != EOF){
          for (mask = 0x80u; mask; mask >>=1)
              printf("%d", !!( c & mask));
     }
          
     fclose(f);                                                     

out:
     return 0;

}



int main(void) { //zad1
    
     int c, val;
     char buf[2] = { '\0', '\0'};
     int bitc, outc;

     bitc = 7;
     outc = 0;
     while((c = fgetc(stdin)) != EOF){
              buf[0] = (char)c;
              val = atoi(buf);
              outc |= val << bitc;
              bitc--;
              if(bitc < 0) {
                      fputc(outc, stdout);
                      outc=0;
                      bitc=7;
            }
      }                                                   
     return 0;
 }                     


int main(void) { //zad1
    
      FILE* f;
    
     int buf[10], j;
     size_t written;

     for(j = 0; j < 10; j++)
         buf[j] = -j;
     f = fopen("bin_file", "w");
     if(!f) goto out;
     written = fwrite(buf,(int) sizeof(int), sizeof(buf)/sizeof(buf[0]), f);
     printf("%z\n", written);
     fclose(f);
out:                                                  
     return 0;
 }


int main(void) {//2

   unsigned le = 0x12345678u, be;

   be = ( (le & 0xffu) << 24) |// shiftvame cqloto 24 napred
        ((le & 0xff00u) << 8) |//56
        ((le & 0xff0000u) >>8) |//34
        ((le & 0xff000000u) >> 24);//12
     
     printf("%x\n");

   return 0;
}*/

int main(void) {
    double phi;

    for( phi = 0.0; phi< 2 * M_PI; phi += 0.001)
           printf("%lf %lf\n", sin(phi), cos(phi));

     return 0;
}






















