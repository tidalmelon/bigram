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


WordType::WordType(std::string w) {
    this->word = w;
    this->pos = new WordTypes(0);
    this->biEntry = new BiMap(0);
    this->pos->total = 1;
}

WordType::~WordType() {
    if (pos != NULL) {
        delete pos;
    }
    if (biEntry != NULL) {
        delete biEntry;
    }
}

std::string WordType::tostring() {
    std::stringstream ss;
    ss << word << ":pos" << this->pos->tostring();
    ss << " BigramMap:" << this->biEntry->tostring();
    return ss.str();
}
