#!/usr/bin/env python3

# 只要是可迭代对象就可以迭代，不管有没有下标

# dict 就可以迭代，但结果不一定是顺序的
d = {'a':1,'b':2,'c':3}
for key in d:
    print(key)
for value in d.values():
    print(value)
for key,value in d.items():
    print("%s = %d" % (key,value))

# str 也可以迭代
for ch in 'ABC':
    print(ch)

# 判断对象是否可以迭代
from collections import Iterable 
print(isinstance('abc',Iterable))
print(isinstance({1,2,3},Iterable))
print(isinstance(123,Iterable))

# enumerate() 可将 list 变成索引-元素对
for i,v in enumerate(['A', 'B', 'C']):
    print(i,v)

# 两个变量同时遍历
for x,y in [(1,2),(3,4),(5,6)]:
    print('(%d,%d)' % (x,y))

# 迭代查找一个 list 的最小值和最大值， tuple 输出
def findMinAndMax(L):
    if isinstance(L,list):
        if L != None:
            min = L[0]
            max = L[0]
            for x in L:
                if x  < min:
                    min = x
                if x > max:
                    max = x
            return min,max
        return None,None
    return None,None

print(findMinAndMax([1,2,4,3,5,0]))