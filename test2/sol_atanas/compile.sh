#!/bin/sh

cc -m32 -I. -I../../lect/queue/include calc.c getstr.c test.c ../../lect/queue/queue.o -o calc
