/*************************************************************************
	> File Name: tst.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月25日 星期六 20时56分34秒
 ************************************************************************/

#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<boost/algorithm/string/classification.hpp>
#include<boost/algorithm/string/split.hpp>

#include "tst.h"
#include "pos.h"
//#include "util.h"

TSTNode::TSTNode(char key) {
    splitChar = key;
    loNode = NULL;
    eqNode = NULL;
    hiNode = NULL;
}

TernarySearchTrie::TernarySearchTrie() {
    rootNode = NULL;
}

void TernarySearchTrie::loadBaseDict(char fname[]) {
    // 词典结构： 词 词性 频率 (是以某个词的某个词性为粒度, 即一个词会出现在多行，但词性不同)
    //char encoding[] = "gb18030";
    std::ifstream in(fname);
    std::string line;
    int num = 0;
    while (getline(in, line)) {
        //std::string outline;
        //decode(line, outline, encoding);

        std::vector<std::string> dest;
        boost::split(dest, line, boost::is_any_of(":"), boost::token_compress_on);
        //std::vector<std::string>::iterator it;
        //for (it=dest.begin(); it!=dest.end(); ++it) {
        //    std::cout << *it << std::endl;
        //}
        //std::cout << "------------------: " << dest.size() <<  std::endl;
        std::string word = dest.at(0);
        std::string pos = dest[1];
        std::string num = dest[2];
        //std::cout << word << " pos:" << pos << " num:" << num << std::endl;
        int value = Pos::getValue(pos);
        //std::cout << pos << ":" << value << std::endl;


    }
}

TSTNode* TernarySearchTrie::getOrCreateNode(std::string word) {

    int charIndex = word.size() - 1;
    if (rootNode == NULL) {
        rootNode = new TSTNode(word.at(0));
    }

    TSTNode *currentNode = rootNode;

    while (true) {
        int compa = word.at(charIndex) - currentNode->splitChar;
        if (compa == 0) {
            if (charIndex <= 0) {
                return currentNode;
            }
            charIndex --;
            if (currentNode->eqNode == NULL) {
                currentNode->eqNode = new TSTNode(word.at(charIndex));
            }
            currentNode = currentNode->eqNode;
        } else if (compa < 0) {
            if (currentNode->loNode == NULL) {
                currentNode->loNode = new TSTNode(word.at(charIndex));
            }
            currentNode = currentNode->loNode;
        } else {
            if (currentNode->hiNode == NULL) {
                currentNode->hiNode = new TSTNode(word.at(charIndex));
            }
            currentNode = currentNode->hiNode;
        }
    }
    return NULL;
}

TSTNode* TernarySearchTrie::getNode(std::string word) {
    int charIndex = word.size() - 1;
    TSTNode *currentNode = rootNode;

    while (true) {
        if (currentNode == NULL) {
            return NULL;
        }
        int compa = word.at(charIndex) - currentNode->splitChar;
        if (compa == 0) {
            if (charIndex <= 0) {
                return currentNode;
            }
            charIndex --;
            currentNode = currentNode->eqNode;
        } else if (compa < 0) {
            currentNode = currentNode->loNode;
        } else {
            currentNode = currentNode->hiNode;
        }
    }
    return NULL;
}
