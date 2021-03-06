/*************************************************************************
    > 用于词性标注
	> 1, 存储同一个词的多种词性及对应频率
    > 2, 存储同一个词的总频率
 ************************************************************************/

#ifndef _WORDTYPES_H
#define _WORDTYPES_H

class WordTypes {

public:
    WordTypes(int len);

    ~WordTypes();

    void put(int key, int val);
    void insert(int i, int key, int val);

    void grow();

    void print();

    std::wstring tostring(); 

public:
    int *keys; //词性
    int *vals; //词性频率
    int  total; //词性的总频率(词的总频率)

public:
    size_t len_arr;

};


#endif
