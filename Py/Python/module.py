#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

#作用域

#类似 _XX __xx __XX__的变量或函数不应当在外部引用

# __doc__可以访问模块的文档注释

import hello_module
print(hello_module.__doc__)
print(hello_module.__author__)

#外部不需要引用的函数定义为 private ，只有外部需要引用的函数定义为 public