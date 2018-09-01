#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

# python 内置的 doctest 模块可以提取注释中的代码并执行测试
# doctest 严格按照 python 交互式命令行的输入和输出来判断测试结果是否正确
# 可以用 ... 表示测试异常中间的一大段输出

class Dict(dict):
    '''
    Simple dict but also support access as x.y style.

    >>> d1 = Dict()
    >>> d1['x'] = 100
    >>> d1.x
    100
    >>> d1.y = 200
    >>> d1['y']
    200
    >>> d2 = Dict(a=1, b=2, c='3')
    >>> d2.c
    '3'
    >>> d2['empty']
    Traceback (most recent call last):
        ...
    KeyError: 'empty'
    >>> d2.empty
    Traceback (most recent call last):
        ...
    AttributeError: 'Dict' object has no attribute 'empty'
    '''
    def __init__(self,**kv):
        super(Dict,self).__init__(**kv)
    def __getattr__(self, key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Dict' object has no attribute '%s'" % key)
    def __setattr__(self, key, value):
        self[key] = value

# practice
def fact(n):
    '''
    Calculate 1*2*...*n

    >>> fact(1)
    1
    >>> fact(10)
    Traceback (most recent call last):
        ...
    RecursionError: maximum recursion depth exceeded in comparison
    >>> fact(-1)
    Traceback (most recent call last):
        ...
    ValueError
    '''
    if n < 1:
        raise ValueError()
    if n == 1:
        return 1
    return n * fact(n)
#模块被导入时不会执行，只有在命令行下才会执行
if __name__ == '__main__':
    import doctest
    doctest.testmod()