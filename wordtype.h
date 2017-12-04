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

class WordType {
public:
    WordType(std::string w);
    ~WordType();
    std::string tostring();
public:
    std::string word;
    WordTypes *pos;
    BiMap *biEntry;
};

#endif
