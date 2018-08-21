#!/usr/bin/env python3

L = ['Michae', 'Sarah', 'Tracy', 'Bob', 'Jack']
# 取前3个元素
print(L[0], L[1], L[2])
for i in range(3):
    print(L[i])
# 切片
print(L[0:3])
print(L[:3])
# 倒数切片
print(L[-3:])

L = list(range(100))
print(L)
print(L[:])
print(L[:10])
print(L[-10:])
print(L[11:20])

# 前10个数，每隔 2 个取一个
print(L[:10:2])

# 所有的数，每隔 5 个取一个
print(L[::5])

# tuple 也可以切片，结果仍是 tuple
print((0, 1, 2, 3, 4, 5)[:3])

# 字符串也可以切片，结果仍是字符串
print('ABCDEFG'[:3])
print('ABCDEFG'[::2])

# practice 切片实现trim函数
def trim(s):
    if isinstance(s,str):
        index1 = 0
        index2 = len(s) -1
        i = index1
        while i <= index2:
            if s[i] != ' ':
                index1 = i
                break
            else:
                i = i + 1
        i = index2
        while i >= index1:
            if s[i] != ' ':
                index2 = i
                break
            else:
                i = i - 1
        return s[index1:index2+1]
print(trim('  12 3 '))