#ifndef _NGRAM_H
#define _NGRAM_H

#include<string>

#include "wordtype.h"
#include "tst.h"

class Ngram {
public:
    Ngram();
    ~Ngram();
    void split(std::wstring sentence);

private:
    int getBigramFreq(WordType *prev, WordType *next);

private:
    TernarySearchTrie *dict;
    size_t _len;

    double lambda1;
    double lambda2;
    
};

#endif
