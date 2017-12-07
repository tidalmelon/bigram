#include<iostream>
#include<sstream>
#include "bimap.h"


BiMap::BiMap(int len) {
    prevIds = new int[len];
    freqs = new int[len];
    this->id = 0;

    this->len = len;
}

BiMap::~BiMap() {
    if (prevIds != NULL) {
        delete [] prevIds;
        prevIds = NULL;
    }
    if (freqs != NULL) {
        delete [] freqs;
        freqs = NULL;
    }
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

int BiMap::index(int prevId) {
    int low = 0;
    int high = this->len - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        int midval = prevIds[mid];
        if (midval < prevId) {
            low = mid + 1;
        } else if (midval > prevId) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
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

std::wstring BiMap::tostring() {
    std::wstringstream ss;
    ss << "BigramMap@";
    for (size_t i=0; i<this->len; i++) {
        ss << "[" << prevIds[i] << ":" << freqs[i] << "]"; 
    }
    if (this->len <= 0) {
        ss << "empty";
    }
    return ss.str();
}


