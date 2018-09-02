#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

# os 模块
# 调用操作系统的接口函数
import os
print(os.name)
print(os.uname()) # windows 不支持

# 环境变量
print(os.environ)
print(os.environ.get('PATH','DefaultIfNot'))

# 操作文件和目录
# 操作文件和目录的函数一部分放在 os 模块中，一部分放在 os.path 中
print(os.path.abspath('.'))
# 合成路径名(跨平台))
print(os.path.join('~/MyCode/Python','Python.py'))
# 创建目录
# os.mkdir('/home/testuser/testdir')
# 删除目录
# os.rmdir('/home/testuser/testdir')
# 拆分路径
print(os.path.split('/home/testuser/testfile.txt'))
# 获取扩展名
print(os.path.splitext('/home/testuser/testfile.txt'))
# 文件重命名
# os.rename('test.txt','text.py')
# 删除文件
# os.remove('test.py')
# 复制文件
from shutil import copyfile
# copyfile('/home/testuser/test.txt','/home/testuser2/')

# 一行代码过滤文件
print([x for x in os.listdir('.') if os.path.isfile(x) and os.path.splitext(x)[1] == '.py'])