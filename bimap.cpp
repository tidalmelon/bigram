#include<iostream>
#include<sstream>
#include "bimap.h"


BiMap::BiMap(int len) {
    prevIds = new int[len];
    freqs = new int[len];
    this->len = len;
}

BiMap::~BiMap() {
    delete [] prevIds;
    prevIds = NULL;
    delete [] freqs;
    freqs = NULL;
}

void BiMap::put(int prevId, int freq) {
    if (len == 0) {
        delete [] prevIds;
        delete [] freqs;
        len += 1;

        prevIds = new int[len];
        freqs = new int[len];

        prevIds[0] = prevId;
        freqs[0] = freq;

        return;
    }

    size_t idx = index_bin(prevIds, prevId, 0, len-1);
    //std::cout << "idx: " << idx << std::endl;
    len += 1;
    int *prevIds_ = new int[len];
    int *freqs_ = new int[len];

    for (size_t i=0; i<len; i++) {
        if (i == idx) {
            prevIds_[i] = prevId;
            freqs_[i] = freq;
        } else if (i > idx) {
            prevIds_[i] = prevIds[i-1];
            freqs_[i] = freqs[i-1];
        } else {
            prevIds_[i] = prevIds[i];
            freqs_[i] = freqs[i];
        }
    }

    delete [] prevIds;
    delete [] freqs;

    prevIds = prevIds_;
    freqs = freqs_;
}

int BiMap::getfreq(int prevId) {

    size_t idx = index(this->prevIds, prevId, 0, len-1);
    if (idx != -1) {
        return this->freqs[idx];
    }
    return -1;
}

size_t BiMap::index(int arr[], int val, size_t left, size_t right) {
    if (left > right) {
        return -1;
    }

    size_t mid = left + ((right - left) >> 1);
    if (arr[mid] == val) {
        return mid;
    } else if (arr[mid] < val) {
        return index(arr, val, mid+1, right);
    } else {
        return index(arr, val, left, mid-1);
    }
}

size_t BiMap::index_bin(int arr[], int val, size_t left, size_t right) {
    if (left == right && left > 0) {
        //std::cout << "left: " << left << std::endl;
        if (arr[left] < val) {
            return left + 1;
        } else {
            return left;
        }
    } else if (left == right && left == 0) {
        if (arr[left] < val) {
            return 1;
        } else {
            return 0;
        }
    }

    size_t mid = left + ((right - left) >> 1);
    if (arr[mid] == val) {
        return mid;
    } else if (arr[mid] < val) {
        return index_bin(arr, val, mid+1, right);
    } else {
        return index_bin(arr, val, left, mid-1);
    }
}

void BiMap::print() {
    std::cout << this->len << std::endl;
    for (int i=0; i<this->len; i++) {
        std::cout << this->prevIds[i] << " ";
    }
    std::cout << std::endl;
    for (int i=0; i<this->len; i++) {
        std::cout << this->freqs[i] << " ";
    }
    std::cout << std::endl;
}

std::string BiMap::tostring() {
    std::stringstream ss;
    ss << "BigramMap@";
    for (size_t i=0; i<this->len; i++) {
        ss << "[" << prevIds[i] << ":" << freqs[i] << "]"; 
    }
    if (this->len <= 0) {
        ss << "empty";
    }
    return ss.str();
}


