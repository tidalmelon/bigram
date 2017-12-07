#include<iostream>
#include "../tst.h"
using namespace std;

int main() {
    TernarySearchTrie t;

    // 测试基本词典
    char fname[] = "../dic/coreDict_utf8.txt";
    t.loadBaseDict(fname);
    //TSTNode *nr = t.getNode(L"会议记录");
    //setlocale(LC_CTYPE, "en_US.UTF-8");
    //wcout << nr->data->tostring() << " 100 " << 100 << endl;

    // 测试二元词典
    char fname1[] = "../dic/BigramDict_u.txt";
    t.loadBigramDict(fname1);

    //TSTNode *nr = t.getNode(L"实验");
    //setlocale(LC_CTYPE, "en_US.UTF-8");
    //wcout << nr->data->tostring() << endl;

    /* cat ../dic/BigramDict_utf8.txt | grep @实验 | wc -l  48 */

    return 0;
}

/*
 * g++ tst_test.cpp ../tst.cpp ../bimap.cpp ../wordtype.cpp ../wordtypes.cpp ../pos.cpp
 */
