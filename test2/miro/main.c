#include <stdio.h>
#include <libc.h>
#include "queue.h"

void calc(FILE *in, FILE *out, queue_object *q);
int byHash(char* str, queue_object* listOfQueues, queue_object* functions);
int byDolar(queue_object *q, char* str);
typedef int (*functionPtr)(int);

int main(void) {
    FILE *in = fopen("file1.txt","r");
    FILE *out = fopen("file2.txt","w+");
    
    if (!in) {
        printf("error");
        return 0;
    }
    queue_object *q = queue_create();
    calc(in,out,q);
    
    fclose(in);
    fclose(out);
    return 0;
}

void calc(FILE *in, FILE *out, queue_object *functions) {
    long size = 8192;
    long readed;
    char c;
    char firstChar;
    char *buffer = (char*) malloc (sizeof(char)*size);
    char *line = (char*) malloc (sizeof(char)*size);;
    char *counter;
    char *navigator;
    int value;
    queue_object* listOfQueues = queue_create();
    // while(readed = fread (buffer,1,size,in)) {

    // }
    readed = fread (buffer,1,size,in);
    navigator = buffer;
    firstChar = *navigator;

    counter = strchr(navigator, '\n');
    memcpy(line, navigator, counter - navigator);
    line[counter - navigator] = '\0';
    if(firstChar == '#') {
        byHash(line, listOfQueues, functions);
    }
    else if(firstChar == '$') {
        byDolar(listOfQueues, navigator);
    }
    
    
     while((navigator = strchr(navigator, '\n'))) {
         navigator++;
         if(!navigator) break;
         
         counter = strchr(navigator, '\n');
         if(counter == NULL) {
             counter = strchr(navigator, '\0');
         }
         memcpy(line, navigator, counter - navigator);
         line[counter - navigator] = '\0';
         
         if(*navigator == '#') {
             byHash(line, listOfQueues, functions);
         }
         else if(*navigator == '$') {
             value = byDolar(listOfQueues, navigator);
             printf("%d\n",value);
         }
     }
//
    
    
    
//    printf("%s\n", buffer);
    buffer[readed] = '\0';
}

int byHash(char* str, queue_object* listOfQueues, queue_object* functions) {
    queue_object *q = queue_create();
    datum d;
    datum container;
    char *pos;
    int num;
    int counter = 0;
    int key = atoi(str + 1);
    
    
    
    for (pos = strchr(str,' '); pos; pos = strchr(pos,' ')) {
        num = atoi(pos);
//        d.type = INT;
//        d.data.i = num;
//        d.on_delete = NULL;
        
        
//        d.type = VOIDP;
//        d.data.vp = functions->search(functions, num, &d);
        void* found = functions->search(functions, num, &d);
        if(!found) {
            return 0;
        }
//        d.on_delete = NULL;
        
        
        q->addE(q, counter, d);
        
        counter++;
    }
    
    container.type = VOIDP;
    container.data.vp = q;
    container.on_delete = NULL;
//     container.on_delete = queue_delete;
    
    listOfQueues->addE(listOfQueues, key, container);
    return 1;
}
int byDolar(queue_object *q, char* str) {
    int key = atoi(str + 1);
    int val = atoi(strchr(str,' '));
    int himKey;
    datum d;
    
    
    queue_object* targetQueue = (queue_object*)q->search(q, key, &d);
    
    functionPtr func;
    while(targetQueue->getE(targetQueue, &himKey, &d)) {
        func = d.data.vp;
        val = (*func)(val);
    }
    
    return val;
}














