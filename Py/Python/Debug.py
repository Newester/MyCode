#!/usr/bin/env python3

#使用 print 将变量打印出来，简单粗暴
def foo(s):
    n = int(s)
    print('>>> n = %d ' % n)
    return 10 / n
def main():
    foo('0')
#main()

#使用断言 assert
#如果断言失败会抛出 AssertionError
def foo_2(s):
    n = int(s)
    assert n != 0, 'n is zero!'
    return 10 / n
def main_2():
    foo('0')
#main_2()
#可以使用 -0 参数关闭 assert
# python3 -0 Debug.py

# logging ，不会抛出错误，还能输出到文件
import logging
logging.basicConfig(level=logging.INFO)
s = '0'
n = int(s)

logging.info('n = %d' % n)
#print(10 / n)

# logging 的级别 debug 、info 、warning 、error
#只有配置的级别以及高于配置的级别才有效

# pdb python 的调试器
# python3 -m pdb Debug.py
# l 显示代码
# 输入代码转到该行
# n 单步执行
# p 查看变量名
# c 继续运行
# q 退出执行

# 设置断点
import pdb
s = '0'
n = int(s)
pdb.set_trace()
print(10 / n)

# IDE vscode，pycharm

