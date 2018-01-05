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
#include<boost/lexical_cast.hpp>

#include "tst.h"
#include "pos.h"
#include "wordtype.h"
//#include "util.h"

TSTNode::TSTNode(wchar_t key) {
    splitChar = key;
    loNode = NULL;
    eqNode = NULL;
    hiNode = NULL;
    data = NULL;
}

TSTNode::~TSTNode() {
    if (loNode != NULL) {
        //std::wcout << "clean:" << splitChar << std::endl;
        delete loNode;
        loNode = NULL;
    }
    if (eqNode != NULL) {
        //std::wcout << "clean:" << splitChar << std::endl;
        delete eqNode;
        eqNode = NULL;
    }
    if (hiNode != NULL) {
        //std::wcout << "clean:" << splitChar << std::endl;
        delete hiNode;
        hiNode = NULL;
    }
    if (data != NULL) {
        delete data;
        data = NULL;
    }
}

TernarySearchTrie::TernarySearchTrie() {
    rootNode = NULL;

    n = 0; //词典中词的总频率
    id = 0; //存储每个词的ID
    nodeId = 0; //节点编号

}

TernarySearchTrie::~TernarySearchTrie() {
    if (rootNode != NULL) {
        delete rootNode;
        rootNode = NULL;
    }
}

void TernarySearchTrie::loadBaseDict(char fname[]) {
    // 词典结构： 词 词性 频率 (是以某个词的某个词性为粒度, 即一个词会出现在多行，但词性不同)
    //char encoding[] = "gb18030";
    std::ifstream in(fname);
    std::string line;
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
        std::string word_ = dest.at(0);
        std::string pos_ = dest[1];
        std::string freq_ = dest[2];
        //std::cout << word << " pos:" << pos << " num:" << num << std::endl;
        //
        std::wstring pos = s2ws(pos_);
        int key = Pos::getValue(pos);

        //std::cout << pos << ":" << key << std::endl;

        std::wstring word = s2ws(word_);
        //std::wcout << word << std::endl;

        int freq = boost::lexical_cast<int>(freq_);

        if (this->rootNode == NULL) {
            this->rootNode = new TSTNode(word[0]);
        }

        TSTNode *currentNode = getOrCreateNode(word);

        if (freq == 0) {
            freq = 1;
        }
        if (currentNode->data == NULL) {
            WordType *data = new WordType(word);
            data->biEntry->id = this->id;
            // 存储每个词的ID
            this->id += 1;
            /*统计同一个词的各种词性及对应频率 */
            data->pos->put(key, freq);
            currentNode->data = data;
        } else {
            /*统计同一个词的各种词性及对应频率 */
            currentNode->data->pos->put(key, freq);
        }
        this->n += freq; //统计词典中总词频
    }
}

void TernarySearchTrie::loadBigramDict(char fname[]) {
    //以@阻止:1 词典格式
    std::ifstream in(fname);
    std::string line;
    while (getline(in, line)) {
        
        std::string::size_type idx = line.find("@");
        if (idx == std::string::npos) {
            continue;
        }
        idx = line.find(":");
        if (idx == std::string::npos) {
            continue;
        }

        std::vector<std::string> dest;
        boost::split(dest, line, boost::is_any_of("@:"), boost::token_compress_on);
        //std::vector<std::string>::iterator it;
        //for (it=dest.begin(); it!=dest.end(); ++it) {
        //    std::cout << *it << std::endl;
        //}
        //std::cout << "------------------: " << dest.size() <<  std::endl;

        std::string prefix_word_ = dest.at(0);
        std::string suffix_word_ = dest.at(1);
        std::string freq_ = dest.at(2);
        
        std::wstring prefix_word = s2ws(prefix_word_);
        std::wstring suffix_word = s2ws(suffix_word_);
        int freq = boost::lexical_cast<int>(freq_); 
        
        TSTNode *suffixNode = getNode(suffix_word);
        if (suffixNode == NULL || suffixNode->data == NULL) {
            continue;
        }

        TSTNode *prefixNode = getNode(prefix_word);
        if (prefixNode == NULL || prefixNode->data == NULL) {
            continue;
        }

        int id = prefixNode->data->biEntry->id; /*前缀单词的Id */
        suffixNode->data->biEntry->put(id, freq);
    }
}

TSTNode* TernarySearchTrie::getOrCreateNode(std::wstring word) {

    int charIndex = word.size() - 1;
    if (rootNode == NULL) {
        rootNode = new TSTNode(word.at(0));
        this->nodeId += 1;
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
                this->nodeId += 1;
            }
            currentNode = currentNode->eqNode;
        } else if (compa < 0) {
            if (currentNode->loNode == NULL) {
                currentNode->loNode = new TSTNode(word.at(charIndex));
                this->nodeId += 1;
            }
            currentNode = currentNode->loNode;
        } else {
            if (currentNode->hiNode == NULL) {
                currentNode->hiNode = new TSTNode(word.at(charIndex));
                this->nodeId += 1;
            }
            currentNode = currentNode->hiNode;
        }
    }
    return NULL;
}

TSTNode* TernarySearchTrie::getNode(std::wstring word) {
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

void TernarySearchTrie::matchAll(std::wstring sentence, int offset, std::vector<WordType*> *ret) {
    ret->clear();
    if (sentence.empty() || rootNode == NULL) {
        return;
    }

    TSTNode *currentNode = rootNode;
    int charIndex = offset;
    while (true) {
        if (currentNode == NULL) {
            if (ret->size() == 0) {
                /* 内存泄漏，但却检测不出来，*/
                ret->push_back(new WordType(sentence.substr(offset, 1), true));
            }
            return;
        }
        //std::wcout << "charIdx:" << charIndex << " word:" << sentence.at(charIndex) << " :" << currentNode->splitChar << std::endl;
        int compa = sentence.at(charIndex) - currentNode->splitChar;
        if (compa == 0) {
            if (currentNode->data != NULL) {
                ret->push_back(currentNode->data);
            }

            if (charIndex <= 0) {
                if (ret->size() == 0) {
                    ret->push_back(new WordType(sentence.substr(offset, 1), true));
                }
                return;
            }
            charIndex --;
            currentNode = currentNode->eqNode;
        } else if (compa < 0) {
            currentNode = currentNode->loNode;
        } else {
            currentNode = currentNode->hiNode;
        }
    }
}

std::wstring TernarySearchTrie::s2ws(const std::string& str) {
    if (str.empty()) {
        return L"";
    }
    unsigned len = str.size() + 1;
    setlocale(LC_CTYPE, "en_US.UTF-8");
    wchar_t *p = new wchar_t[len];
    mbstowcs(p, str.c_str(), len);
    std::wstring w_str(p);
    delete [] p;
    return w_str;
}

