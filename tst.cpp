/*************************************************************************
	> File Name: tst.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月25日 星期六 20时56分34秒
 ************************************************************************/

#include<fstream>
#include<string>
#include<iostream>

#include "tst.h"
#include "util.h"

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
    char encoding[] = "GBK";
    std::ifstream in(fname);
    std::string line;
    while (getline(in, line)) {
        std::string outline;
        int res = decode(line, outline, encoding);
        std::cout << outline << std::endl;
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
