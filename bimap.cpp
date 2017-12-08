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
    int idx = index(prevId);
    if (idx == -1) {
        this->grow();
        for (idx=len-1; idx>0 && prevIds[idx-1]>prevId; idx--) {
            prevIds[idx] = prevIds[idx-1];
            freqs[idx] = freqs[idx-1];
        }
    }
    prevIds[idx] = prevId;
    freqs[idx] = freq;
}

void BiMap::grow() {
    len += 1;
    int *prevIds_ = new int[len];
    int *freqs_ = new int[len];
    for (int i=0; i<len-1; i++) {
        prevIds_[i] = prevIds[i];
        freqs_[i] = freqs[i];
    }
    prevIds_[len-1] = 0;
    freqs_[len-1] = 0;

    delete [] prevIds;
    delete [] freqs;

    prevIds = prevIds_;
    freqs = freqs_;
}

int BiMap::getfreq(int prevId) {
    int idx = index(prevId);
    if (idx != -1) {
        return this->freqs[idx];
    }
    return -1;
}

int BiMap::index(int prevId) {
    int low = 0;
    int high = this->len - 1;
    while (low <= high) {
        //int mid = low + ((high - low) >> 1);
        int mid = (low + high) / 2;
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
    for (int i=0; i<this->len; i++) {
        ss << "[" << prevIds[i] << ":" << freqs[i] << "]"; 
    }
    if (this->len <= 0) {
        ss << "empty";
    }
    return ss.str();
}


