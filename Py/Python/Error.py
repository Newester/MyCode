#!/usr/bin/env python3
# _*_ coding: utf-8 _*_
try:
    print('try...')
    r = 10 / 0
    print('result:', r)
except ZeroDivisionError as e:
    print('except：', e)
finally:
    print('finally...')
print('END')
#如果没有发生错误 except 语句不会被执行
#如果有 finally 语句，一定会被执行

#不同类型的错误应当有不同类型的 except 语句来处理
try:
    print('try...')
    r = 10 / int('a')
    print('result:', r)
except ValueError as e:
    print('ValueError:', e)
except ZeroDivisionError as e:
    print('ZeroDivisionError:', e)
finally:
    print('finally...')
print('END')

#如果没有错误发生，可以在后面加一个 else 语句
try:
    print('try...')
    r = 10 / int('2')
    print('result:', r)
except ValueError as e:
    print('ValueError:', e)
except ZeroDivisionError as e:
    print('ZeroDivisionError:', e)
else:
    print('No error!')
finally:
    print('finally...')
print('END')

# python 的错误也是 class ，所有的错误类型都继承自 BaseException ，所以在使用 except 时需要注意它不但捕获该类型的错误，还把其子类也一网打尽
#第二个 except 语句永远不会被执行，因为 UnicodeError 是 ValueError 的子类
def func():
    pass
try:
    func()
except ValueError as e:
    print('ValueError:', e)
except UnicodeError as e:
    print('UnicodeError:', e)

# try ... except 可以跨多层调用
def foo(s):
    return 10 / int(s)
def bar(s):
    return foo(s) * 2
def main():
    try:
        bar('0')
    except Exception as e:
        print('Error:', e)
    finally:
        print('finally...')
main()  

def main_2():
    bar('0')
# 如果错误没有捕获，它就会一直往上抛，直到被 python 解释器捕获,打印错误信息，退出程序
#main_2()
#！！！出错时一定要分析调用栈信息，定位错误！！！

# logging 模块，记录错误信息
import logging
def main_3():
    try:
        bar('0')
    except Exception as e:
        logging.exception(e)
main_3()
print('END')

# raise 语句，抛出一个错误的实例
class FooError(ValueError):
    pass

def foo_2(s):
    n = int(s)
    if n == 0:
        raise FooError('invalid value: %s' % s)
    return 10 / n
#foo_2('0')

# 捕获错误，打印记录，然后抛给上层处理
def bar_2():
    try:
        foo_2('0')
    except FooError as e:
        print('ValueError!')
bar_2()

# raise 语句不带参数就把当前错误原样抛出
# except ... raise ... 可以将一个错误类型转换为另一错误类型抛出
def bar_3():
    try:
        foo_2('0')
    except FooError as e:
        raise ZeroDivisionError('ZeroDivisionError:', e)

def main_4():
    try:
        bar_3()
    except ZeroDivisionError as e:
        print('ZeroDivisionError!')
    finally:
        print('finally...')
    print('END')
main_4()
