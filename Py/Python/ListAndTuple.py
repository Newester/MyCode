#!/usr/bin/env python3

#list

classmates = ['Michael', 'Bob', 'Tracy']
print(classmates)

print(len(classmates))

print(classmates[0])

print(classmates[1])

print(classmates[2])

# 索引超出范围 IndexError:list index out of range
# print(classmates[3])

print(classmates[-1])

print(classmates[-2])

print(classmates[-3])

# 索引超出范围 IndexError:list index out of range 
# print(classmates[-4])

#list是可变的有序表
classmates.append('Adam')
print(classmates)

#插到指定索引的位置
classmates.insert(0,'Jack')
print(classmates)

#删除末尾的元素
print(classmates.pop())
print(classmates)

print(classmates.pop(1))
print(classmates)

#list中的元素类型可以不同
l = ['Apple', 123, True]
print(l)

#list中的元素可以是list
s = ['python', 'java', ['asp', 'php'], 'scheme']
print(len(s))
print(s)
print(s[2][1])

#空的list长度为0
L = []
print(len(L))



## tuple 一经初始化就不能修改

classmates = ('Michael', 'Bob', 'Tracy')
print(classmates)
print(classmates[0])
print(classmates[-1])

# tuple 定义时元素就必须被确定下来
t = (1,2)
print(t)

#定义一个空的 tuple 
t = ()
print(t)

#定义只有一个元素的 tuple 必须用逗号消除歧义
t = (1,)
print("没有逗号将被当做小括号：")
print("有逗号 t = (1,) ==> ",t)
t = (1)
print("没有逗号  t = (1) ==> ",t)

# tuple 本身不可变，但是 tuple 内部的元素是可变的
t = ('a','b',['c','d'])
print(t)
print("len(t) =",len(t))

t[2][0] = 'x'
t[2][1] = 'y'
print(t)
t[2].append('e')
print(t)


