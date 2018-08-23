#!/usr/bin/env python3

#偏函数创建一个新函数固定住原来函数的参数值
import functools

int2 = functools.partial(int,base=2)

#如下会将10加入形参列表的最左边
max2 = functools.partial(max,10)