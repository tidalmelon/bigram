#include<iostream>
#include<string>
#include "../wordtypes.h"

#include "../wordtoken.h"
using namespace std;

int main() {
    WordTypes *wts = new WordTypes(0);

    wts->put(1, 2);
    wts->put(2, 3);
    wts->put(20, 3);
    wts->put(100, 2);
    wts->put(2, 3);
    wts->put(20, 3);


    wts->print();

    std::wstring line = wts->tostring();

    std::cout << "==============" << std::endl;
    std::wcout << line << std::endl;

    //delete wts;
    WordToken *token = new WordToken(1, 2, L"中国", wts);
    wcout << token->tostring() << endl;

    delete token;

//1 2 20 100 2 20 
//2 3 3 2 3 3 
    
    return 0;


}
