/*************************************************************************
    > 用于词性标注
	> 1, 存储同一个词的多种词性及对应频率
    > 2, 存储同一个词的总频率
 ************************************************************************/
#include<iostream>
#include<string>
#include "../wordtypes.h"

//class WordTypes {
//
//public:
//    WordTypes(int len) {
//        this->keys = new int[len];
//        this->vals = new int[len];
//        this->len_arr = len;
//    }
//
//    ~WordTypes() {
//        if (keys != NULL) {
//            delete [] keys;
//        }
//        if (vals != NULL) {
//            delete [] vals;
//        }
//    }
//
//    void put(int key, int val) {
//        this->grow();
//        this->keys[len_arr-1] = key;
//        this->vals[len_arr-1] = val;
//    }
//
//    void grow() {
//        int *keys_ = new int[this->len_arr + 1];
//        int *vals_ = new int[this->len_arr + 1];
//
//        for (size_t i=0; i<this->len_arr; i++) {
//            keys_[i] = keys[i];
//            vals_[i] = vals[i];
//        }
//
//        this->len_arr += 1;
//        delete [] keys;
//        delete [] vals;
//
//        keys = keys_;
//        vals = vals_;
//    }
//
//    void print() {
//        for (size_t i=0; i<this->len_arr; i++) {
//            std::cout << keys[i] << " ";
//        }
//        std::cout << std::endl;
//        for (size_t i=0; i<this->len_arr; i++) {
//            std::cout << vals[i] << " ";
//        }
//        std::cout << std::endl;
//    }
//    
//
//public:
//    int *keys;
//    int *vals;
//    int  total;
//
//private:
//    size_t len_arr;
//
//};

int main() {

    WordTypes wts(0);

    wts.put(1, 2);
    wts.put(2, 3);
    wts.put(20, 3);
    wts.put(100, 2);
    wts.put(2, 3);
    wts.put(20, 3);


    wts.print();

    std::string line = wts.tostring();

    std::cout << "==============" << std::endl;
    std::cout << line << std::endl;



//1 2 20 100 2 20 
//2 3 3 2 3 3 
    
    return 0;
}
