#!/usr/bin/env python3

# open('/path/to/file','r') -- 打开文件（只读UTF8文本方式）
f = open('test.txt','r')
# 文件不存在会报 IOError 错误
# f = open('noexsit.txt','r')
s = f.read()
print(s)
# close() -- 关闭文件
f.close()

# 文件读写时也可能产生 IOError ，需要异常处理
try:
    f = open('test.txt','r')
    print(f.read())
finally:
    if f:
        f.close()
# with 语句可以起到同样的效果，不必调用 f.close() 方法
with open('test.txt','r') as f:
    print(f.read())

# read() 一次性读取文件
# read(size) 一次读取 size 字节
# readline() 一次读取一行
# readlines() 一次读取所有行并且按行存入 list
f = open('test.txt','r')
for line in f.readlines():
    print(line.strip()) #去掉末尾的 '\n'
f.close()

# file-like Object 可由 open() 方法返回的具有 read() 方法的对象
# file 、字节流、网络流、自定义流、StringIO 等

#读取二进制文件
f = open('liaoxuefeng.jpg','rb')
print(f.read())
f.close()

#文本字符编码，默认 utf-8
f = open('test.txt','r',encoding='utf8')
print(f.read())
f.close()

#忽略文本编码不规范造成的 UnicodeDecodeError，也可以其他方式处理
f = open('test.txt','r',encoding='gbk',errors='ignore')
print(f.read())
f.close()

#写文件 write()
# 'w' ：已存在则覆盖； 'a' ： 追加
f = open('test.txt','w', encoding='utf8')
f.write('Hello, world!')
f.close()
f = open('test.txt','r',encoding='utf8')
print(f.read())
f.close()