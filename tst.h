/*************************************************************************
	> File Name: tst.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月25日 星期六 20时38分32秒
 ************************************************************************/

#ifndef _TST_H
#define _TST_H

#include<string>
#include<vector>
#include "wordtype.h"

class TSTNode {
    public:
        wchar_t splitChar;
        //std::string data;
        //std::wstring data;
        WordType *data;
        TSTNode(wchar_t key);
        ~TSTNode();

        TSTNode *loNode;
        TSTNode *eqNode;
        TSTNode *hiNode;
};

class TernarySearchTrie {
    public:
        TSTNode *rootNode;

        TernarySearchTrie();
        ~TernarySearchTrie();

        void loadBaseDict(char fname[]);
        void loadBigramDict(char fname[]);
        TSTNode* getOrCreateNode(std::wstring word);
        TSTNode* getNode(std::wstring word);
        void matchAll(std::wstring sentence, int offset, std::vector<WordType*> *ret);
    private:
        std::wstring s2ws(const std::string& str);

    public:
        double n; // 词典中词的总频率
        int id; // 存储每个词的ID
        int nodeId; //节点编号


};

#endif
