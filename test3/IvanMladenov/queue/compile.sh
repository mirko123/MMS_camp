#!/bin/sh -x

cc -m32 -c -g -Iinclude -Iinternal/include internal/src/queue.c
cc -m32 -Iinclude -Iinternal/include queue.o -shared -fPIC -o libqueue.so
