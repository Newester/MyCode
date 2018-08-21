#!/usr/bin/env python3

# 函数式编程 (Functional Programing)
#   允许函数本身作为参数传入，允许返回一个函数
#   python 提供一定的函数式编程支持，但由于允许使用变量，不是纯的函数式编程语言

# 高阶函数 Higher-order function

#变量可以指向函数
print(abs)

x = abs(10)
print(x)

f = abs
print(f)
print(f(10))

#函数名也是变量
#abs = 10
#import builtins;builtins.abs = 10
# 改变函数的名的指向后，函数名不再是原来那个函数

#高阶函数 一个函数可以接受另一个函数作为参数

def add(x, y, f):
    return f(x)+f(y)

print(add(-5,6,abs))

# map 接受两个参数，一个 Iterable ，一个 function 。
# map　将传入的函数依次作用到序列的每个元素，并把结果作为新的 Iterator 返回

def fun(x):
    return x*x

r = map(fun,[1,2,3,4,5,6,7,8,9])
print(list(r))

print(list(map(str,[1,2,3,4,5,6,7,8,9])))

# reduce 把一个接受两个参数的函数作用在序列上，先将序列的第1、第2个元素传给函数计算结果，再将结果与第3个元素继续传给函数，以此类推，累积运算

# reduce 求和
from functools import reduce
def add_2(x, y):
    return x + y
print(reduce(add_2,[1,3,5,7,9]))

# str2int() 函数

#from functools import reduce

DIGITS = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}

def str2int(s):
    def fn(x,y):
        return x*10+y
    def char2num(s):
        return DIGITS[s]
    return reduce(fn,map(char2num,s))

print(str2int('12345'))

# 运用 lambda 进一步化简
#from functools import reduce
#DIGITS = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}


def char2num_2(s):
    return DIGITS[s]

def str2int_2(s):
    return reduce(lambda x,y: x*10+y,map(char2num_2,s))

print(str2int_2('56789'))

# practice 首字母大写
def ToName(w):
    return w.capitalize()

def AllToName(s):
    return list(map(ToName,s))
print(AllToName(['adam','LISA','barT']))

# practice 连乘积
def multi(x,y):
    return x*y
def prod(nums):
    return reduce(multi,nums)

print(prod([1,2,3,4,5]))


# practice 字符串转浮点数
CHAR_TO_FLOAT = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    '.': -1
}
# 廖雪峰不要脸，啥时候讲过闭包了？
def str2float(s):
    nums = map(lambda ch: CHAR_TO_FLOAT[ch], s)
    decimal = False
    i = 1
    def to_float(f, n):
        nonlocal decimal
        nonlocal i
        if n == -1:
            decimal = True
            return f
        if decimal == False:
            return f * 10 + n
        else:
            i = i * 10
            return f + n / i
    return reduce(to_float, nums, 0.0)

print(str2float('0'))
print(str2float('123.456'))
print(str2float('123.45600'))
print(str2float('0.1234'))
print(str2float('.1234'))
print(str2float('120.0034'))



