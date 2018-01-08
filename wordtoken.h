#ifndef _WORDTOKEN_H
#define _WORDTOKEN_H

#include<string>
#include "wordtypes.h"

class WordToken {
public:
    WordToken(int vertexfrom, int vertexto, std::wstring word, WordTypes* d);
    ~WordToken();
    std::wstring tostring();

public:
    std::wstring termText;
    WordTypes* data;
    int start;
    int end;
    int p;
    std::wstring pn;
};

#endif
