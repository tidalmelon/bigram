# -*- coding: utf-8 -*-

import ctypes
from ctypes import c_wchar_p

lib = ctypes.cdll.LoadLibrary("./libngram.so")
lib.split(c_wchar_p(u'产品和服务'))
lib.split(c_wchar_p(u'有意见分歧'))
lib.split(c_wchar_p(u'京东是购物的天堂'))

lib.split(c_wchar_p(u'今天我写了一个程序'))
