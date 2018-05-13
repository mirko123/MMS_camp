#include<stdio.h>

void calc(FILE *in, FILE *out, queue_object *q) {
    int data;
    long size = 8000; 
    char *token = "#$";
    long readed; 

    int d1, d2, d3, d4, d5, d6, d7;

    char *ss, *p;

    char helper[5];
 
    char *buff =(char*) malloc(sizeof(char)* size);

    readed = fread( buff, 1,size,in);
    buff[readed] = '\0';
	
    ss = strdup(buff);
	
	for (p = strtok(ss, token); p; p = strtok(NULL, token))
{
      if( p[0] == '#') {
    
        if( p[1] == '0') {
         
           helper[0] == '1';            

           queue_object *obj1;

	   obj1 = queue_create();
	   if (!obj1) return 1;

           search(q, 1,d1);
           search(q, 3,d3);
           search(q, 4,d4);

           addB(obj1,4,d4);
           addB(obj1,3,d3);
           addB(obj1, 1, d1);
}
      if( p[1] == '1') {
         
           helper[1] == '1';            

           queue_object *obj2;

	   obj2 = queue_create();
	   if (!obj2) return 1;

           search(q, 2,d2);
           search(q, 5,d5);

           addB(obj2,5,d5);
           addB(obj2,2,d2);
          
}
       if( p[1] == '3') {
         
           helper[2] == '1';            

           queue_object *obj3;

	   obj3 = queue_create();
	   if (!obj3) return 1;

           search(q, 5,d5);
           search(q, 7,d7);
           

           addB(obj3,7,d7);
           addB(obj3,5,d5);
           
}
       if( p[1] == '4') {
         
           helper[3] == '1';            

           queue_object *obj4;

	   obj4 = queue_create();
	   if (!obj4) return 1;

           search(q, 0,d0);
           search(q, 4,d4);
           search(q, 5,d5);

           addB(obj4,5,d4);
           addB(obj4,4,d3);
           addB(obj4, 0, d1);
}
       if( p[1] == '5') {
         
           helper[4] == '1';            

           queue_object *obj1;

	   obj1 = queue_create();
	   if (!obj) return 1;

           search(q, 3,d3);
           search(q, 4,d4);
           search(q, 6,d6);

           addB(obj1,6,d6);
           addB(obj1,4,d4);
           addB(obj1, 3, d3);
} 
      else printf("error");
    
}


     else if ( p[o] == '$') {
 
     if( p[1] == '0') {
     if(helper[0] != '1') printf("error")
    else

}
}


}

		            
   


    free(buff);

}
