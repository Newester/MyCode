#!/usr/bin/env python3

#传入函数时有时不需要显式地定义函数，传入匿名函数更加方便
# 求平方
print(list(map(lambda x : x*x, [1,2,3,4,5,6,7,8,9])))

# 关键字 lambda 表示匿名函数，冒号前面表示函数参数，后面是函数体表达式

#匿名函数的函数体只能有一个表达式，不用写 return 语句，返回值就是这个表达式的结果

#匿名函数没有名字不用担心函数名冲突

#匿名函数是一个函数对象，可以值给一个变量，再利用该变量调用函数

f = lambda x : x * x
print(f)
print(f(5))

#　可以返回匿名函数
def highfunc(x,y):
    return lambda: x * x + y * y

#practice 匿名函数返回奇数列
L = list(filter(lambda n : n %2 == 1, range(1,20)))
print(L)