#!/usr/bin/env python3
#调用函数
print(abs(-12.34))

#函数传参不对会报错
#abs(1,2)
#abs('a')

# 有些函数可接收任意多个参数，如 max()
print(max(1,2))
print(max(1,2,3,4,5))

# python 内置了一些类型转换函数
print(int('123'))
print(float('12.34'))
print(str(1.23))
print(bool(1))
print(bool(100))
print(bool(''))
print(bool("123"))

# 函数名是一个指向函数对象的引用
# 可以把函数名赋给一个变量，相当于起一个别名
a = abs
print(a(-19.25))

# hex() 函数将一个整数转换成16进制表示的字符串
print(hex(1205))
print(type(hex(12)))

# 函数调用要传入正确的参数，如果出错一定要看错误信息

#自定义函数
def my_abs(x):
    if x >= 0:
        return x
    else:
        return -x
print(my_abs(-23))

# 不带 return 和 return 和 return None 是一样的
def func1():
    return
# 定义一个空函数
# pass可以用作占位符，类似TODO
def func2():
    pass
def func3():
    return None

print(func1())
print(func2())
print(func3())

# python解释器能够检查参数个数，但不能检查参数类型
#print(my_abs("123"))

def new_abs(x):
    if not isinstance(x,(int,float)):
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x
#print(new_abs("123"))

# 函数返回多值
import math
pi = math.pi
def move(x, y, step, angle=0):
    nx = x + step * math.cos(angle)
    ny = y - step * math.sin(angle)
    return nx,ny

x, y = move(100,100,10,math.pi/4)
print("(%d,%d)" % (x,y))

# 函数返回多值实际上是返回一个 tuple
pos = move(10,10,10,pi/4)
print(pos)

# 定义函数时，确定函数名和参数个数
# 如有必要，可以先进行参数类型检查
# 函数体内可以用 return 语句随时返回结果，没有 return 函数执行完毕返回 None
# 函数可以返回多值，实际上是一个 tuple

# 计算平方根
print(math.sqrt(9))

# practice
def quadratic(a, b, c):
    print("%dx^2+(%dx)+(%d)=0" % (a,b,c))
    if b*b - 4*a*c < 0:
        return print("No result.")
    x1 = (-b + math.sqrt(b*b - 4*a*c)) / 2*a
    x2 = (-b - math.sqrt(b*b - 4*a*c)) / 2*a
    return x1,x2
print(quadratic(1,-2,1))

def power(x):
    return x*x
print(power(3))

def power_2(x, n):
    r = 1
    while n > 0:
        r = r * x
        n = n - 1
    return r

# 设置默认参数：默认参数必须放在后面，否则将报错
#定义函数时应当有意识地将变化大的参数放前面，变化小的参数放后面可作为默认参数
def pwoer_3(x, n = 2):
    r = 1
    while n > 0:
        r = r * x
        n = n - 1
    return r
# power_2(x)
print(pwoer_3(2),pwoer_3(2,3))

# 有多个默认参数时，可以按顺序传参，也可以不按顺序传参
def enroll(name, gender, age = 6, city = 'Beijing'):
    print('name :', name)
    print('gender :', gender)
    print('age :', age)
    print('city :', city)

enroll('Bob', 'M', 7)

#不按顺序传参需指定形参名
enroll('Adam', 'M', city='Tianjin') 


#！！！默认参数必须指向不可变对象！！！

#这是一个坑
def add_end(L = []):
    L.append('END')
    return L
print(add_end())
print(add_end())
print(add_end())

def add_end_2(L = None):
    if L is None:
        L = []
    L.append('END')
    print(L)
    return L

add_end_2()
add_end_2()
add_end_2()

# 不可变对象同时读时可以不用加锁，如何允许尽量定义成不可变对象

def clac(numbers):
    sum = 0
    for n in numbers:
        sum = sum + n
    return sum

#可变参数，在形参名前加 * 号
def clac_2(*numbers):
    sum = 0
    for n in numbers:
        sum = sum + n
    return sum
print(clac([1,2,3,4,5]))
print(clac_2(1,2,3,4,5))
print(clac_2(*[1,2,3,4,5]))

#关键字参数，在形参名前加 ** 号
# 允许传入0个或任意个含参数名的参数，将它们组装成dict
# ！！！需要和形参名一起传入
def person(name, age, **kv):
    print("name = %s, age = %d" % (name, age))
    print("other:",kv)

person('Michael',20)
person('Michael',20, gender='M' ,country='China')
extra = {'city':'Beijing','job':'Engineer'}
person('Jack',24,**extra) # 此时传入的是一份拷贝，在函数内的修改不会影响到 extra 的值

# 命名关键字参数，需要一个特殊分隔符 * ，* 后面的参数被视为命名关键字参数
def person_2(name, age, *, city, job):
    print(name,age,city,job)

person_2('Jack',24,city='Beijing',job='Engineer')

#如果已经有了一个可变参数，后面跟的命名关键字不再需要特殊分隔符
def person_3(name, age, *args, city, job):
    print(name,age,args,city,job)
person_3('Thomas',24,"Not use",city="Beijing",job="Engineer")

#!!!命名关键字必须传入形参名！！！

#命名关键字可以有缺省值
def person_4(name, age, *, city='Beijing', job):
    print(name,age,city,job)
person_4('Jane',21,job='Engineer')

# 必选参数、默认参数、可变参数、关键字参数、命名关键字参数可以组合使用
def f1(a, b , c=0, *args, **kv):
    print('a=', a, 'b=', b, "c=", c, 'args=', args, 'kv=', kv)

def f2(a, b, c=0, *, d, **kv):
    print('a=', a, 'b=', b, 'c=', c, 'd=', d, 'kv=', kv)

f1(1,2)
f1(1,2,c=3)
f1(1,2,3,args=(),kv={})
f1(1,2,3,'a','b')
f1(1,2,3,'a','b',x=99)
f2(1,2,d=99,ext=None,ext2=True)

# 传入一个 tuple 和 一个 dict ，也可以调用上述函数
args1=(1,2,3,4)
kv1={'d':99,'x':'#'}
f1(*args1,**kv1)

#对于任意参数，不论形参列表是怎样的，都可以通过 func(*args,**kw) 形式进行调用

#practice 计算乘积
def product(x,*numbers):
    r = x
    for n in numbers:
        r = r * n
    print(r)
    return r

product(1,2,3)
product(1,2,3,4,5)


# Python的函数具有非常灵活的参数形态，既可以实现简单的调用，又可以传入非常复杂的参数。

# 默认参数一定要用不可变对象，如果是可变对象，程序运行时会有逻辑错误！

# 要注意定义可变参数和关键字参数的语法：

# *args是可变参数，args接收的是一个tuple；

# **kw是关键字参数，kw接收的是一个dict。

# 以及调用函数时如何传入可变参数和关键字参数的语法：

# 可变参数既可以直接传入：func(1, 2, 3)，又可以先组装list或tuple，再通过*args传入：func(*(1, 2, 3))；

# 关键字参数既可以直接传入：func(a=1, b=2)，又可以先组装dict，再通过**kw传入：func(**{'a': 1, 'b': 2})。

# 使用*args和**kw是Python的习惯写法，当然也可以用其他参数名，但最好使用习惯用法。

# 命名的关键字参数是为了限制调用者可以传入的参数名，同时可以提供默认值。

# 定义命名的关键字参数在没有可变参数的情况下不要忘了写分隔符*，否则定义的将是位置参数。


# 函数递归 一个函数在内部调用自身
# 计算阶乘
def fac(n):
    if n == 1:
        return 1
    return n * fac(n-1)
print(fac(4))

#递归调用次数过多将可能导致栈溢出
#fac(1000)

#尾递归 函数返回时调用自身，且 return 不包含表达式
#尾递归和循环是等价的
def fact(n):
    return fact_iter(n,1)

def fact_iter(num, product):
    if num == 1:
        return product
    return fact_iter(num -1,num*product)
# python 没有针对尾递归做优化，所以尾递归也还是可能栈溢出
#fact_iter(1000,1)

#practice 汉诺塔
### 汉诺塔（或称“河内塔”）：借助柱子 B ，将 A 柱上从小到大上下排列的圆盘移动到 C 柱上
#   1.一次只能移动一个圆盘
#   2.小圆盘必须在大圆盘上  
#  思路：逆向思维，要想最后在C上排好-->最大的那个要放到C的最下面-->此时 C 要是空的，A 只剩最下面那个 --> 所有n-1个都在B上排好了
#                --> 然后将A上的那个移到C --> 此时 A 空了，C只有一个最大的不需要动 --> 借助 A 将 B 上的都移到 C
def move(n, a, b, c):
    if n == 1:
        print('move', a,'-->', c)
    else:
        move(n-1,a,c,b) # 先把 n-1 个在 B上排好
        move(1,a,b,c)  # 再把 A 上 剩下最大那个移到 C
        move(n-1,b,a,c)  # 再把 B 上的 n-1 个移到 C
move(20,'A','B','C')
    