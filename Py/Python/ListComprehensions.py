#!/usr/bin/env python3

list(range(1,11))

L = []
for x in range(1,11):
    L.append(x*x)
print(L)

# 列表生成式
L = [x*x for x in range(1,11)]
print('L =',L)

L = [x*x for x in range(1,11) if x % 2 == 0]
print(L)

L = [ m+n for m in 'ABC' for n in '123']
print('L =', L)
d = { 'x':'1','y':'2','z':'3'}
print([k+'='+v for k,v in d.items()])

# 列出当前目录下的所有文件和目录名
import os
print([d for d in os.listdir('.')])

# 把一个 list 中的字符串变成小写
L = ['Hello',2,'World',1]
print([s.lower() for s in L if isinstance(s,str)])