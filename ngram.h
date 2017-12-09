#include<string>
#include "tst.h"

#ifndef _NGRAM_H
#define _NGRAM_H

class NgramTokenizer {
public:
    NgramTokenizer();
    void split(std::wstring sentence);
private:
    TernarySearchTrie *dict;
};


#endif
