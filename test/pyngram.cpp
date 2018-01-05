#include<iostream>
//#include<stdio.h>
#include<string>
#include "../ngram.h"


extern "C" {
    Ngram nm;
    void split(wchar_t *sen) {
        //setlocale(LC_CTYPE, "en_US.UTF-8");
        nm.split(sen);
    }
    //void split(std::wstring sen) {
    //    setlocale(LC_CTYPE, "en_US.UTF-8");
    //    nm.split(sen);
    //}
}
