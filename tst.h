/*************************************************************************
	> File Name: tst.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月25日 星期六 20时38分32秒
 ************************************************************************/

#ifndef _TST_H
#define _TST_H

#include<string>

class TSTNode {
    public:
        char splitChar;
        std::string data;
        TSTNode(char key);

        TSTNode *loNode;
        TSTNode *eqNode;
        TSTNode *hiNode;
};

class TernarySearchTrie {
    public:
        TSTNode *rootNode;

        TernarySearchTrie();

        void loadBaseDict(char fname[]);
        TSTNode* getOrCreateNode(std::string word);
        TSTNode* getNode(std::string word);

};

#endif
