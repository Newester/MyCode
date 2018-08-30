#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

'a test module' #任何模块代码的第一个字符串都会被视为模块的文档注释

__author__ = 'Sepro Wan'
import sys
def test():
    args = sys.argv
    if len(args) == 1:
        print('Hello world!')
    elif len(args) == 2:
        print('Hello %s!' % args[1])
    else:
        print("Too many arguments!")

if __name__ == '__main__': #只有命令行运行时才能会执行这段代码，或者直接调用hello_module.test()
    test()
class Hello(object):
    def hello(self,name='world'):
        print('Hello, %s' % name)
