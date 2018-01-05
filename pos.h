/*************************************************************************
	> 词性表
 ************************************************************************/

#ifndef _POS_H
#define _POS_H

#include<map>

class Pos {
public:
    std::wstring getName(int pos);
    static int getValue(std::wstring key);
	static int start;
	static int end;
	static int a;
	static int ad;
	static int ag;
	static int an;
	static int b;
	static int c;
	static int d;
	static int dg;
	static int e;
	static int f;
	static int g;
	static int h;
	static int i;
	static int j;
	static int k;
	static int l;
	static int m;
	static int n;
	static int ng;
	static int nr;
	static int ns;
	static int nt;
	static int nx;
	static int nz;
	static int o;
	static int p;
	static int q;
	static int r;
	static int s;
	static int t;
	static int tg;
	static int u;
	static int ud;
	static int ug;
	static int uj;
	static int ul;
	static int uv;
	static int uz;
	static int v;
	static int vd;
	static int vg;
	static int vn;
	static int w;
	static int x;
	static int y;
	static int z;
	static int unknow;

    static std::wstring names[];
    static std::map<std::wstring, int> values;
};

#endif
