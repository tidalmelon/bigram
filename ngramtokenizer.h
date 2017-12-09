#include<string>

#include "tst.h"

#ifndef _NGRAMTOKENIZER_H
#define _NGRAMTOKENIZER_H

class NgramTokenizer {
public:
    NgramTokenizer();
    void split(std::wstring sentence);
private:
    TernarySearchTrie *dict;

};


#endif
