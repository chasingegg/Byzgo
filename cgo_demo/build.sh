#!/bin/sh

cd foo
gcc -c foo.c -std=c99
ar -crs libfoo.a foo.o
cd ..

cd fplus
g++ -c fplus.cpp
g++ -c bridge.c
ar -crs libfplus.a fplus.o bridge.o
cd ..

go build
