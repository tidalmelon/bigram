# n-gram - 二元分词

## c++实例
```
c++
Ngram nm;
nm.split(L"产品和服务");

```

## python示例
```
# -*- coding: utf-8 -*-

import ctypes
from ctypes import c_wchar_p

lib = ctypes.cdll.LoadLibrary("./libngram.so")
lib.split(c_wchar_p(u'产品和服务'))
lib.split(c_wchar_p(u'有意见分歧'))
lib.split(c_wchar_p(u'京东是购物的天堂'))

lib.split(c_wchar_p(u'今天我写了一个程序'))
```

分词+词性标注
```
text:产品 [pos:n, 19] [start:0, end:2] data: pos:freq[19:779]
text:和 [pos:c, 7] [start:2, end:3] data: pos:freq[27:209][7:10694][4:1][20:1][19:2][21:1][40:9][28:1]
text:服务 [pos:vn, 43] [start:3, end:5] data: pos:freq[40:256][19:1][43:490]
#####################
text:有 [pos:v, 40] [start:0, end:1] data: pos:freq[21:1][18:2][19:1][43:1][40:4638]
text:意见 [pos:n, 19] [start:1, end:3] data: pos:freq[19:180]
text:分歧 [pos:n, 19] [start:3, end:5] data: pos:freq[40:1][19:39][43:1]
#####################
text:京东 [pos:ns, 22] [start:0, end:2] data: pos:freq[22:1]
text:是 [pos:v, 40] [start:2, end:3] data: pos:freq[7:1][2:1][29:6][20:1][19:1][8:1][21:1][40:9826]
text:购物 [pos:v, 40] [start:3, end:5] data: pos:freq[43:15][40:17]
text:的 [pos:uj, 36] [start:5, end:6] data: pos:freq[36:54477]
text:天堂 [pos:n, 19] [start:6, end:8] data: pos:freq[19:8][21:1]
#####################
text:今天 [pos:t, 31] [start:0, end:2] data: pos:freq[31:866][19:1]
text:我 [pos:r, 29] [start:2, end:3] data: pos:freq[40:1][29:1802]
text:写 [pos:v, 40] [start:3, end:4] data: pos:freq[15:1][43:1][40:279]
text:了 [pos:ul, 37] [start:4, end:5] data: pos:freq[37:10234][46:1242][43:1][40:81]
text:一个 [pos:m, 18] [start:5, end:7] data: pos:freq[18:1889]
text:程序 [pos:n, 19] [start:7, end:9] data: pos:freq[21:1][19:46]
#####################
```

##todo:  
    python 安装包
