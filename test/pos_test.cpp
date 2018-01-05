#include<iostream>
#include<string>
#include<map>
#include "../pos.h"

//class Pos {
//public:
//    std::string getName(int pos) {
//        return names[pos];
//    }
//
//	static int start;
//	static int end;
//	static int a;
//	static int ad;
//	static int ag;
//	static int an;
//	static int b;
//	static int c;
//	static int d;
//	static int dg;
//	static int e;
//	static int f;
//	static int g;
//	static int h;
//	static int i;
//	static int j;
//	static int k;
//	static int l;
//	static int m;
//	static int n;
//	static int ng;
//	static int nr;
//	static int ns;
//	static int nt;
//	static int nx;
//	static int nz;
//	static int o;
//	static int p;
//	static int q;
//	static int r;
//	static int s;
//	static int t;
//	static int tg;
//	static int u;
//	static int ud;
//	static int ug;
//	static int uj;
//	static int ul;
//	static int uv;
//	static int uz;
//	static int v;
//	static int vd;
//	static int vg;
//	static int vn;
//	static int w;
//	static int x;
//	static int y;
//	static int z;
//	static int unknow;
//
//    static std::string names[];
//    static std::map<std::string, int> values;
//};
//
//std::string Pos::names[] = {"start","end","a","ad","ag","an","b","c","d","dg","e","f","g","h","i","j","k","l","m","n","ng","nr","ns","nt","nx","nz","o","p","q","r","s","t","tg","u","ud","ug","uj","ul","uv","uz","v","vd","vg","vn","w","x","y","z","unknow"};
//
//int Pos::start = 0;//开始
//int Pos::end = 1;//结束
//int Pos::a = 2;//形容词
//int Pos::ad = 3;//副形词
//int Pos::ag = 4;//形语素
//int Pos::an = 5;//名形词
//int Pos::b = 6;//区别词
//int Pos::c = 7;//连词
//int Pos::d = 8;//副词
//int Pos::dg = 9;//副语素
//int Pos::e = 10;//叹词
//int Pos::f = 11;//方位词
//int Pos::g = 12;//语素
//int Pos::h = 13;//前接成分
//int Pos::i = 14;//成
//int Pos::j = 15;//简称略语
//int Pos::k = 16;//后接成分
//int Pos::l = 17;//习用语
//int Pos::m = 18;//数词
//int Pos::n = 19;//名词
//int Pos::ng = 20;//名语素
//int Pos::nr = 21;//人名
//int Pos::ns = 22;//地名
//int Pos::nt = 23;//机构团体
//int Pos::nx = 24;//字母专名
//int Pos::nz = 25;//其他专名
//int Pos::o = 26;//拟声词
//int Pos::p = 27;//介词
//int Pos::q = 28;//量词
//int Pos::r = 29;//代词
//int Pos::s = 30;//处所词
//int Pos::t = 31;//时间词
//int Pos::tg = 32;//时语素
//int Pos::u = 33;//助词
//int Pos::ud = 34;//结构助
//int Pos::ug = 35;//时态助词
//int Pos::uj = 36;//结构助词的
//int Pos::ul = 37;//时态助词了
//int Pos::uv = 38;//结构助词地
//int Pos::uz = 39;//时态助词着
//int Pos::v = 40;//动词
//int Pos::vd = 41;//副动词
//int Pos::vg = 42;//动语素
//int Pos::vn = 43;//名动词
//int Pos::w = 44;//标点符号
//int Pos::x = 45;//非语素字
//int Pos::y = 46;//语气词
//int Pos::z = 47;//状态词
//int Pos::unknow = 48; //未知
//
//std::map<std::string, int> init() {
//    std::map<std::string, int> tmp;
//
//    tmp["start"] = Pos::start;//开始
//    tmp["end"] = Pos::end;//结束
//    tmp["a"] = Pos::a;//形容词
//    tmp["ad"] = Pos::ad;//副形词
//    tmp["ag"] = Pos::ag;//形语素
//    tmp["an"] = Pos::an;//名形
//    tmp["b"] = Pos::b;//区别词
//    tmp["c"] = Pos::c;//连词
//    tmp["d"] = Pos::d;//副词
//    tmp["dg"] = Pos::dg;//副语素
//    tmp["e"] = Pos::e;//叹
//    tmp["f"] = Pos::f;//方位词
//    tmp["g"] = Pos::g;//语素
//    tmp["h"] = Pos::h;//前接成分
//    tmp["i"] = Pos::i;//成语
//    tmp["j"] = Pos::j;//简称略语
//    tmp["k"] = Pos::k;//后接成分
//    tmp["l"] = Pos::l;//习用语
//    tmp["m"] = Pos::m;//数词
//    tmp["n"] = Pos::n;//名词
//    tmp["ng"] = Pos::ng;//名语素
//    tmp["nr"] = Pos::nr;//人名
//    tmp["ns"] = Pos::ns;//地名
//    tmp["nt"] = Pos::nt;//机构团体
//    tmp["nx"] = Pos::nx;//字母专名
//    tmp["nz"] = Pos::nz;//其他专名
//    tmp["o"] = Pos::o;//拟声词
//    tmp["p"] = Pos::p;//介词
//    tmp["q"] = Pos::q;//量词
//    tmp["r"] = Pos::r;//代词
//    tmp["s"] = Pos::s;//处所词
//    tmp["t"] = Pos::t;//时间词
//    tmp["tg"] = Pos::tg;//时语素
//    tmp["u"] = Pos::u;//助词
//    tmp["ud"] = Pos::ud;//结构助词
//    tmp["ug"] = Pos::ug;//时态助词
//    tmp["uj"] = Pos::uj;//结构助词的
//    tmp["ul"] = Pos::ul;//时态助词了
//    tmp["uv"] = Pos::uv;//结构助词地
//    tmp["uz"] = Pos::uz;//时态助词着
//    tmp["v"] = Pos::v;//动词
//    tmp["vd"] = Pos::vd;//副动词
//    tmp["vg"] = Pos::vg;//动语素
//    tmp["vn"] = Pos::vn;//名动词
//    tmp["w"] = Pos::w;//标点符号
//    tmp["x"] = Pos::x;//非语素字
//    tmp["y"] = Pos::y;//语气词
//    tmp["z"] = Pos::z;//状态词
//    tmp["unknow"] = Pos::unknow; //未知
//    return tmp;
//}
//
//std::map<std::string, int> Pos::values(init());
//

int main() {
    std::cout << Pos::start << std::endl;

    //for (int i=0; i<49; i++) {
    //    std::wcout << Pos::names[i] << std::endl;
    //}

    //Pos p;

    //std::wstring pos = p.getName(1);
    //std::wcout << pos << std::endl;

    //std::map<std::wstring, int>::iterator iter;
    //for (iter=Pos::values.begin(); iter != Pos::values.end(); iter++) {
    //    std::wcout << "key:" << iter->first << " value: " << iter->second << std::endl;
    //}

    //std::wcout << "-----------find by key----------" << std::endl;

    //std::wcout << Pos::getValue(L"vn") << std::endl;

    return 0;
}
