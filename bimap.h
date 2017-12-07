/*************************************************************************
	> 二元词典存储
    > 主要接口：
      插入排序
      二分查找
 ************************************************************************/

#ifndef _BIMAP_H
#define _BIMAP_H

class BiMap {
public:
    BiMap(int len);
    ~BiMap();
    void put(int prevId, int freq);
    int getfreq(int prevId); 
    void print();
    std::wstring tostring();
public:
    int id; //词本身的id

private:
    int index(int prevId);

private:
    int *prevIds;
    int *freqs;

    size_t len;

};

#endif
