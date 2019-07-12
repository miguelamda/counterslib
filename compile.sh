#!/bin/bash

cd obj
g++ -c ../src/timestat.cpp -I../inc

cd ../lib
ar rcs libtimestat.a ../obj/timestat.o

