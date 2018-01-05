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
//#include "pos.h"


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

WordType::WordType(std::wstring w, WordTypes* types, BiMap* b) {
    this->word = w;
    this->pos = types;
    this->biEntry = b;
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

//WordType* WordType::GetStartWord() {
//    WordTypes* types = new WordTypes(1);
//    types->insert(0, Pos::start, 1000);
//    WordType* start = new WordType(L"start", types, NULL);
//    return start;
//}

std::wstring WordType::tostring() {
    std::wstringstream ss;
    ss << this->word << ":pos" << this->pos->tostring();
    if (this->biEntry == NULL) {
        ss << L" BigramMap:NULL";
        return ss.str();
    } 
    ss << L" BigramMap:" << this->biEntry->tostring();
    return ss.str();
}
