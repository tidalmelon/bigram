/*************************************************************************
	> File Name: wordtoken.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Dec 2017 05:17:19 PM CST
 ************************************************************************/

#include<iostream>
#include<sstream>
#include "wordtoken.h"

WordToken::WordToken(int vertexfrom, int vertexto, std::wstring word, WordTypes* d) {
    this->start = vertexfrom;
    this->end = vertexto;
    this->termText = word;
    this->data = d;
}
WordToken::~WordToken() {
    if (data != NULL) {
        delete data;
    }
}

std::wstring WordToken::tostring() {
    std::wstringstream ss;
    ss << "text:" << this->termText;
    ss << " [pos:" << this->pn << ", " << this->p << "]";
    ss << " [start:" << this->start << ", end:" << this->end << "]";
    ss << " data:" << this->data->tostring();
    return ss.str();
}

