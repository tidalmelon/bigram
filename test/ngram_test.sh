#!/bin/bash
g++  ngram_test.cpp ../ngram.cpp ../tag.cpp ../wordtype.cpp ../tst.cpp ../bimap.cpp ../wordtypes.cpp ../pos.cpp ../wordtoken.cpp
#if [$? -ne 0]; then
#    echo "compile failed"
#else
#    ./a.out
#fi
