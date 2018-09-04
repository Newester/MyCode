#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

# StringIO 
# 在内存中读写 str
from io import StringIO
f = StringIO()
print(f.write('hello'))
print(f.write(' '))
print(f.write('world!'))
print(f.getvalue())

f = StringIO('Hello!\nHi!\nGoodbye!')
while True:
    s = f.readline()
    if s == '':
        break
    print(s.strip())

# BytesIO
# 操作二进制数据
from io import BytesIO
f = BytesIO()
f.write('中文'.encode('utf-8'))
print(f.getvalue())
f = BytesIO(b'\xe4\xb8\xe6\x96\x87')
print(f.read())
