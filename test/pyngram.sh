#!/bin/bash
g++  -o libngram.so -shared -fPIC  ./pyngram.cpp ../ngram.cpp ../tag.cpp ../wordtype.cpp ../tst.cpp ../bimap.cpp ../wordtypes.cpp ../pos.cpp ../wordtoken.cpp
