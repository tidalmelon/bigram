/*************************************************************************
	> 三叉Trie树叶子节点：word信息-> 单词
    >                                单词的各种词性及频率
    >                                单词的二元词典
 ************************************************************************/

#ifndef _WORDTYPE_H
#define _WORDTYPE_H

#include<string>
#include "wordtypes.h"
#include "bimap.h"
#include "pos.h"

class WordType {
public:
    WordType(std::wstring w);
    WordType(std::wstring w, bool del);
    WordType(std::wstring w, WordTypes* types, BiMap* b);
    ~WordType();
    std::wstring tostring();

    static WordType* GetStartWord();
public:
    std::wstring word;
    WordTypes *pos;
    BiMap *biEntry;

    bool del;
};

#endif
