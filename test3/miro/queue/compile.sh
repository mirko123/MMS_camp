#!/bin/sh -x

cc -m32 -mt -c -g -Iinclude -Iinternal/include internal/src/queue.c
cc -m32 -mt -Iinclude -Iinternal/include queue.o -shared -fPIC -o libqueue.so -lpthread
