#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

#高阶函数不仅可以接收函数作为参数，还能返回函数
#情境：写一个求和函数，但不需要立即求和　-->　返回求和函数
def lazy_sum(*args):
    def sum():
        ax = 0
        for n in args:
            ax = ax + n
        return ax
    return sum
f = lazy_sum(1,3,5,7,9)
print(f)
print(f())

#将高阶函数返回的函数赋值给变量时，即使高阶函数的新参列表相同，返回的也不是同一个函数
f1 = lazy_sum(1,2,3,4,5)
f2 = lazy_sum(1,2,3,4,5)
print(f1 == f2)
#如上 f1 f2 的调用互不影响

#闭包　注意返回函数不要引用任何循环变量或者后续会发生变化的量
def count():
    fs = []
    for i in range(1,4):
        def f():
            return i*i
        fs.append(f)
    return fs
func1,func2,func3 = count()
print(func1())
print(func2())
print(func3())
# 如果一定要引用循环变量,应该再创建一个函数，用该函数２绑定循环变量当前的值
def count_2():
    def f(j):
        def g():
            return j*j
        return g
    fs = []
    for i in range(1,4):
        fs.append(f(i))
    return fs
f4,f5,f6 = count_2()
print(f4())
print(f5())
print(f6())       

#practice 利用闭包返回一个计数器函数，每次调用它返回递增函数
def createCounter():
    x = 0
    def counter():
        nonlocal x
        x = x + 1
        return x
    return counter
countA = createCounter()
print(countA(),countA(),countA())
countB = createCounter()
print(countB(),countB())