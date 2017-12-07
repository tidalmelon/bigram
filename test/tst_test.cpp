#include<iostream>
#include "../tst.h"
using namespace std;

int main() {

    //此测试作废
    //TernarySearchTrie t;

    //TSTNode *n1 = t.getOrCreateNode(L"中国人民大学");
    //n1->data = L"中国人民大学";
    //
    //TSTNode *n2 = t.getOrCreateNode(L"中国人");
    //n2->data = L"中国人";

    //TSTNode *n3 = t.getOrCreateNode(L"中国人民");
    //n3->data = L"中国人民";

    //TSTNode *nr = t.getNode(L"中国人");

    //setlocale(LC_CTYPE, "en_US.UTF-8");
    //wcout << nr->data << " 100 " << 100 << endl;
    
    TernarySearchTrie t;

    char fname[] = "../dic/coreDict_utf8.txt";
    t.loadBaseDict(fname);

    TSTNode *nr = t.getNode(L"会议记录");
    setlocale(LC_CTYPE, "en_US.UTF-8");
    wcout << nr->data->tostring() << " 100 " << 100 << endl;


    return 0;
}

/*
 * g++ tst_test.cpp ../tst.cpp ../util.cpp
 */
