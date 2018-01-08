#ifndef _TAG_H
#define _TAG_H

#include<deque>
#include "wordtoken.h"


class Tagger {
public:
    Tagger();
    void loadModel(char fname[]);
    double getTransProb(int curState, int toTranState);
    void hmm(std::deque<WordToken*> ret);
private:
    std::wstring s2ws(const std::string& str);

private:
    int typeFreq[49];
    int transFreq[49][49];

};

#endif
