#include<iostream>
#include<map>
#include "pos.h"

std::wstring Pos::names[] = {L"start",L"end",L"a",L"ad",L"ag",L"an",L"b",L"c",L"d",L"dg",L"e",L"f",L"g",L"h",L"i",L"j",L"k",L"l",L"m",L"n",L"ng",L"nr",L"ns",L"nt",L"nx",L"nz",L"o",L"p",L"q",L"r",L"s",L"t",L"tg",L"u",L"ud",L"ug",L"uj",L"ul",L"uv",L"uz",L"v",L"vd",L"vg",L"vn",L"w",L"x",L"y",L"z",L"unknow"};

int Pos::start = 0;//开始
int Pos::end = 1;//结束
int Pos::a = 2;//形容词
int Pos::ad = 3;//副形词
int Pos::ag = 4;//形语素
int Pos::an = 5;//名形词
int Pos::b = 6;//区别词
int Pos::c = 7;//连词
int Pos::d = 8;//副词
int Pos::dg = 9;//副语素
int Pos::e = 10;//叹词
int Pos::f = 11;//方位词
int Pos::g = 12;//语素
int Pos::h = 13;//前接成分
int Pos::i = 14;//成
int Pos::j = 15;//简称略语
int Pos::k = 16;//后接成分
int Pos::l = 17;//习用语
int Pos::m = 18;//数词
int Pos::n = 19;//名词
int Pos::ng = 20;//名语素
int Pos::nr = 21;//人名
int Pos::ns = 22;//地名
int Pos::nt = 23;//机构团体
int Pos::nx = 24;//字母专名
int Pos::nz = 25;//其他专名
int Pos::o = 26;//拟声词
int Pos::p = 27;//介词
int Pos::q = 28;//量词
int Pos::r = 29;//代词
int Pos::s = 30;//处所词
int Pos::t = 31;//时间词
int Pos::tg = 32;//时语素
int Pos::u = 33;//助词
int Pos::ud = 34;//结构助
int Pos::ug = 35;//时态助词
int Pos::uj = 36;//结构助词的
int Pos::ul = 37;//时态助词了
int Pos::uv = 38;//结构助词地
int Pos::uz = 39;//时态助词着
int Pos::v = 40;//动词
int Pos::vd = 41;//副动词
int Pos::vg = 42;//动语素
int Pos::vn = 43;//名动词
int Pos::w = 44;//标点符号
int Pos::x = 45;//非语素字
int Pos::y = 46;//语气词
int Pos::z = 47;//状态词
int Pos::unknow = 48; //未知

std::map<std::wstring, int> init() {
    std::map<std::wstring, int> tmp;

    tmp[L"start"] = Pos::start;//开始
    tmp[L"end"] = Pos::end;//结束
    tmp[L"a"] = Pos::a;//形容词
    tmp[L"ad"] = Pos::ad;//副形词
    tmp[L"ag"] = Pos::ag;//形语素
    tmp[L"an"] = Pos::an;//名形
    tmp[L"b"] = Pos::b;//区别词
    tmp[L"c"] = Pos::c;//连词
    tmp[L"d"] = Pos::d;//副词
    tmp[L"dg"] = Pos::dg;//副语素
    tmp[L"e"] = Pos::e;//叹
    tmp[L"f"] = Pos::f;//方位词
    tmp[L"g"] = Pos::g;//语素
    tmp[L"h"] = Pos::h;//前接成分
    tmp[L"i"] = Pos::i;//成语
    tmp[L"j"] = Pos::j;//简称略语
    tmp[L"k"] = Pos::k;//后接成分
    tmp[L"l"] = Pos::l;//习用语
    tmp[L"m"] = Pos::m;//数词
    tmp[L"n"] = Pos::n;//名词
    tmp[L"ng"] = Pos::ng;//名语素
    tmp[L"nr"] = Pos::nr;//人名
    tmp[L"ns"] = Pos::ns;//地名
    tmp[L"nt"] = Pos::nt;//机构团体
    tmp[L"nx"] = Pos::nx;//字母专名
    tmp[L"nz"] = Pos::nz;//其他专名
    tmp[L"o"] = Pos::o;//拟声词
    tmp[L"p"] = Pos::p;//介词
    tmp[L"q"] = Pos::q;//量词
    tmp[L"r"] = Pos::r;//代词
    tmp[L"s"] = Pos::s;//处所词
    tmp[L"t"] = Pos::t;//时间词
    tmp[L"tg"] = Pos::tg;//时语素
    tmp[L"u"] = Pos::u;//助词
    tmp[L"ud"] = Pos::ud;//结构助词
    tmp[L"ug"] = Pos::ug;//时态助词
    tmp[L"uj"] = Pos::uj;//结构助词的
    tmp[L"ul"] = Pos::ul;//时态助词了
    tmp[L"uv"] = Pos::uv;//结构助词地
    tmp[L"uz"] = Pos::uz;//时态助词着
    tmp[L"v"] = Pos::v;//动词
    tmp[L"vd"] = Pos::vd;//副动词
    tmp[L"vg"] = Pos::vg;//动语素
    tmp[L"vn"] = Pos::vn;//名动词
    tmp[L"w"] = Pos::w;//标点符号
    tmp[L"x"] = Pos::x;//非语素字
    tmp[L"y"] = Pos::y;//语气词
    tmp[L"z"] = Pos::z;//状态词
    tmp[L"unknow"] = Pos::unknow; //未知
    return tmp;
}

std::map<std::wstring, int> Pos::values(init());


std::wstring Pos::getName(int pos) {
    return names[pos];
}

int Pos::getValue(std::wstring key) {
    std::map<std::wstring, int>::iterator it;
    it = values.find(key);
    if (it!= values.end()) {
        return it->second;
    }
    return -1;
}


