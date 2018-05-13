#!/bin/sh -x

cc -m32 -Iinclude -Iinternal/include internal/src/queue.c -shared -fPIC -o libqueue.so
cc -m32 -Iinclude -L. queuetest.c -lqueue -o queuetest
