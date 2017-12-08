/*************************************************************************
	> 三叉Trie树叶子节点：word信息-> 单词
    >                                单词的各种词性及频率
    >                                单词的二元词典
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
#include "wordtypes.h"
#include "bimap.h"
#include "wordtype.h"


WordType::WordType(std::wstring w) {
    this->word = w;
    this->pos = new WordTypes(0);
    this->biEntry = new BiMap(0);
    this->pos->total = 1;
    this->del = false;
}

WordType::WordType(std::wstring w, bool del) {
    this->word = w;
    this->pos = new WordTypes(0);
    this->biEntry = new BiMap(0);
    this->pos->total = 1;

    this->del = true;
}

WordType::~WordType() {
    if (pos != NULL) {
        delete pos;
    }
    if (biEntry != NULL) {
        delete biEntry;
    }
}

std::wstring WordType::tostring() {
    std::wstringstream ss;
    ss << word << ":pos" << this->pos->tostring();
    ss << L" BigramMap:" << this->biEntry->tostring();
    return ss.str();
}
