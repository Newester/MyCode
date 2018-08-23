#!/usr/bin/env python3
# _*_coding:utf8 _*_

# sorted() 函数可对 list 排序
print(sorted([36,-5,-12,9,21]))

# sorted() 是一个高阶函数，可以接收一个 key 函数来实现自定义排序
print(sorted([36,-5,12,9,17],key=abs))

# 字符串排序默认是按照 ASCII 码
print(sorted(['Hello','world','hi','my','friend']))

#无关大小写的排序
print(sorted(['Hello','world','hi','my','friend'],key=str.lower))

#反向排序
print(sorted(['Hello','world','hi','my','friend'],reverse=True))

# practice 按名字排序
L = [('Bob',75),('Adam',92),('Bart',66),('Lisa',88)]


def byname(t):
    return t[:1]
def byscore(t):
    return t[-1:]
print(sorted(L,key=byname))
print(sorted(L,key=byscore))