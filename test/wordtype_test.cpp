#include<iostream>
#include "../wordtype.h"

//g++ wordtype_test.cpp ../wordtype.cpp ../wordtypes.cpp ../bimap.cpp

int main() {

    std::wstring word = L"席尔瓦";
    WordType wt(word);

    wt.pos->put(1, 2);
    wt.pos->put(1, 2);
    wt.pos->put(2, 3);
    wt.pos->put(20, 3);
    wt.pos->put(100, 2);
    wt.pos->put(2, 3);
    wt.pos->put(20, 3);

    wt.biEntry->put(2, 20);
    wt.biEntry->put(11, 110);
    wt.biEntry->put(3, 30);
    wt.biEntry->put(7, 70);
    wt.biEntry->put(13, 130);
    wt.biEntry->put(12, 120);

    std::wstring line = wt.tostring();

    
    setlocale(LC_CTYPE, "en_US.UTF-8");
    std::wcout << line << std::endl;

    return 0;
}
