#include<iostream>
#include "boost/range.hpp"
using namespace std;
#include "../bimap.h"

//class BiMap {
//public:
//    BiMap(int len) {
//        prevIds = new int[len];
//        freqs = new int[len];
//        this->len = len;
//    }
//
//    ~BiMap() {
//        delete [] prevIds;
//        prevIds = NULL;
//        delete [] freqs;
//        freqs = NULL;
//    }
//
//    void put(int prevId, int freq) {
//        if (len == 0) {
//            delete [] prevIds;
//            delete [] freqs;
//            len += 1;
//
//            prevIds = new int[len];
//            freqs = new int[len];
//
//            prevIds[0] = prevId;
//            freqs[0] = freq;
//
//            return;
//        }
//
//        size_t idx = index_bin(prevIds, prevId, 0, len-1);
//        //std::cout << "idx: " << idx << std::endl;
//        len += 1;
//        int *prevIds_ = new int[len];
//        int *freqs_ = new int[len];
//
//        for (size_t i=0; i<len; i++) {
//            if (i == idx) {
//                prevIds_[i] = prevId;
//                freqs_[i] = freq;
//            } else if (i > idx) {
//                prevIds_[i] = prevIds[i-1];
//                freqs_[i] = freqs[i-1];
//            } else {
//                prevIds_[i] = prevIds[i];
//                freqs_[i] = freqs[i];
//            }
//        }
//
//        delete [] prevIds;
//        delete [] freqs;
//
//        prevIds = prevIds_;
//        freqs = freqs_;
//    }
//
//    int getfreq(int prevId) {
//
//        size_t idx = index(this->prevIds, prevId, 0, len-1);
//        if (idx != -1) {
//            return this->freqs[idx];
//        }
//        return -1;
//    }
//
//    size_t index(int arr[], int val, size_t left, size_t right) {
//        if (left > right) {
//            return -1;
//        }
//    
//        size_t mid = left + ((right - left) >> 1);
//        if (arr[mid] == val) {
//            return mid;
//        } else if (arr[mid] < val) {
//            return index(arr, val, mid+1, right);
//        } else {
//            return index(arr, val, left, mid-1);
//        }
//    }
//
//    size_t index_bin(int arr[], int val, size_t left, size_t right) {
//        if (left == right && left > 0) {
//            //std::cout << "left: " << left << std::endl;
//            if (arr[left] < val) {
//                return left + 1;
//            } else {
//                return left;
//            }
//        } else if (left == right && left == 0) {
//            if (arr[left] < val) {
//                return 1;
//            } else {
//                return 0;
//            }
//        }
//    
//        size_t mid = left + ((right - left) >> 1);
//        if (arr[mid] == val) {
//            return mid;
//        } else if (arr[mid] < val) {
//            return index_bin(arr, val, mid+1, right);
//        } else {
//            return index_bin(arr, val, left, mid-1);
//        }
//    }
//
//    void print() {
//        std::cout << this->len << std::endl;
//        for (int i=0; i<this->len; i++) {
//            std::cout << this->prevIds[i] << " ";
//        }
//        std::cout << std::endl;
//        for (int i=0; i<this->len; i++) {
//            std::cout << this->freqs[i] << " ";
//        }
//        std::cout << std::endl;
//   }
//
//
//    //void grow() {
//    //    this->prevIds = copy(this->prevIds, this->len);
//    //    this->freqs = copy(this->freqs, this->len);
//    //    this->len += 1;
//    //}
//
//    //int* copy(int *arr, int len) {
//    //    size_t new_len = len + 1;
//    //    int *new_arr = new int[new_len];
//    //    for (int i=0; i<len; i++) {
//    //        new_arr[i] = *(arr+i);
//    //    }
//    //    new_arr[len] = 0;
//
//    //    for (int i=0; i<new_len; i++) {
//    //        std::cout << " --" << new_arr[i] << std::endl;
//    //    }
//
//    //    delete arr;
//    //    arr = NULL;
//
//    //    return new_arr;
//    //}
//
//
//private:
//    int *prevIds;
//    int *freqs;
//
//    size_t len;
//
//};


int main() {
    // test grow()
    //BiMap m(10);
    //m.print();
    //std::cout << "-------grow-------" << std::endl;
    //m.grow();
    //m.print();
    //

    BiMap m(0);

    m.put(2, 20);
    m.put(11, 110);
    m.put(3, 30);
    m.put(7, 70);
    //m.put(3, 31);
    m.put(13, 130);
    m.put(12, 120);

    m.print();

    std::cout << "-----------" << std::endl;

    int freq = m.getfreq(11);
    std::cout << "11:" << freq << std::endl;

    freq = m.getfreq(2);
    std::cout << "2:" << freq << std::endl;

    freq = m.getfreq(6);
    std::cout << "6:" << freq << std::endl;

    freq = m.getfreq(7);
    std::cout << "7:" << freq << std::endl;

    freq = m.getfreq(15);
    std::cout << "15:" << freq << std::endl;

    return 0;
}
