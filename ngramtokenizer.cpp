#include<iostream>
#include<string>
#include "ngramtokenizer.h"

NgramTokenizer::NgramTokenizer() {
    this->dict = new  TernarySearchTrie();
    char fname[] = "../dic/coreDict_utf8.txt";
    this->dict->loadBaseDict(fname);

    char fname1[] = "../dic/BigramDict_u.txt";
    this->dict->loadBigramDict(fname1);
}

void NgramTokenizer::split(std::wstring sentence) {

}
