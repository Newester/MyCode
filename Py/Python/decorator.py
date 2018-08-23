#函数也是一个对象，函数对象可以被赋值给变量，通过变量也能调用函数
def now():
    print('2018-08-24')
f = now
f()

#函数有一个 name 属性，可以拿到函数的名字
print(now.__name__)
print(f.__name__)

#装饰器　－－　在运行期动态增加函数功能的方式
#增强 now() 函数的功能，但不修改其定义
# decorator 本质是一个高阶函数，接收一个函数作为参数并返回一个函数
def log(func):
    def wrapper(*args,**kv):
        print('call %s:' % func.__name__)
        return func(*args,**kv)
    return wrapper

# decorator 使用时需要用到 @ 语法
@log #相当于执行语句 now_2 = log(now_2)
def now_2():
    print('2018-08-24')

now_2()

#如果 decorator 本身需要传递参数，那就需要编写一个返回 decorator 的高阶函数

def log_2(text):
    def decorator(func):
        def wrapper(*args,**kv):
            print('%s %s():' % (text,func.__name__))
            return func(*args,**kv)
        return wrapper
    return decorator

@log_2('excute') # 相当于 now_3 = log('excute')(now_3)
def now_3():
    print('2018-08-24')
now_3()
#以上decorator的问题是函数的 __name__　属性值发生了改变
print(now_3.__name__)

#需要将原始函数的　__name__　等属性复制到 wrapper() 函数中
import functools
def log_3(func):
    @functools.wraps(func)
    def wrapper(*args,**kv):
        print('call %s():' % func.__name__)
        return func(*args,**kv)
    return wrapper

def log_4(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args,**kv):
            print('%s %s()' % (text,func.__name__))
            return func(*args,**kv)
        return wrapper
    return decorator

@log_3
def now_4():
    print('2018-08-24')
now_4()

fun = now_4
print(fun.__name__)
@log_4('excute')
def now_5():
    print('2018-08-24')
now_5()
fun = now_5
print(fun.__name__)

# practice 打印函数执行时间

import os,time
def logTime(func):
    @functools.wraps(func)
    def metric(*args,**kv):
        print('%s executed in %s' % (func.__name__,time.asctime()))
        return func(*args,**kv)
    return metric

@logTime
def hello():
    time.sleep(0.0012)
    print("say hi to you.")

hello()