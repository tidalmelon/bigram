#include<iostream>
#include "wordtypes.h"
#include<sstream>


WordTypes::WordTypes(int len) {
    this->keys = new int[len];
    this->vals = new int[len];
    this->len_arr = len;
}

WordTypes::~WordTypes() {
    if (keys != NULL) {
        delete [] keys;
    }
    if (vals != NULL) {
        delete [] vals;
    }
}

void WordTypes::put(int key, int val) {
    this->grow();
    this->keys[len_arr-1] = key;
    this->vals[len_arr-1] = val;
}

void WordTypes::insert(int i, int key, int val) {
    this->keys[i] = key;
    this->vals[i] = val;
}


void WordTypes::grow() {
    int *keys_ = new int[this->len_arr + 1];
    int *vals_ = new int[this->len_arr + 1];

    for (size_t i=0; i<this->len_arr; i++) {
        keys_[i] = keys[i];
        vals_[i] = vals[i];
    }

    this->len_arr += 1;
    delete [] keys;
    delete [] vals;

    keys = keys_;
    vals = vals_;
}

void WordTypes::print() {
    for (size_t i=0; i<this->len_arr; i++) {
        std::cout << keys[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i=0; i<this->len_arr; i++) {
        std::cout << vals[i] << " ";
    }
    std::cout << std::endl;
}

std::wstring WordTypes::tostring() {
    std::wstringstream ss;
    ss << " pos:freq";
    for (size_t i=0; i<this->len_arr; i++) {
        ss << "[" << keys[i] << ":" << vals[i] << "]"; 
    }
    if (this->len_arr <= 0) {
        ss << "empty";
    }
    return ss.str();
}
    
