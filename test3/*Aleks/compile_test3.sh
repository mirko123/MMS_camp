#!/bin/sh -x

cc -Iinclude -Iinternal/include internal/src/queue.c -pthread test3.c -o test3
./test3 za_gencho
