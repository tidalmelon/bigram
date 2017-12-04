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
    std::string tostring();

private:
    size_t index(int arr[], int val, size_t left, size_t right);
    size_t index_bin(int arr[], int val, size_t left, size_t right);

private:
    int *prevIds;
    int *freqs;
    size_t len;

};

#endif
