#!/usr/bin/env python3

names = ['Michael','Bob','Tracy']
scores = [95, 75, 85]

# dict 索引表，键值对 kye-value

d = {'Michael':95, 'Bob':75, 'Tracy':85}
print(d['Michael'])

# 把数据放入 dict
d['Adam'] = 67
print(d)

d['Adam'] = 95
print(d['Adam'])
print(d)

# key 不存在会报错
# d['Thomas']

#通过 in 判断 key 是否存在
print('Thomas' in d)

# 通过 get() 方法， key 不存在返回空
print(d.get('Adam'))
print(d.get('Thomas'))

# 指定自己的 value
print(d.get('Thomas', 100))
print(d) #并没有插入到字典中

# dict 查找插入速度快，不会随着key的增加而变慢，但是内存占用大

# dict 的 key 必须不可变（计算位置采用 hash 算法）

# set 
# 只保存 key ，不存在 value

#创建 key 要提供一个 list
s = set([1,2,3])
print(s)

# add(key) 方法向 set 中添加元素
s.add(4)
print(s)

# 重复添加是允许的，但没有效果
s.add(1)
print(s)

# remove(key) 方法删除元素
s.remove(4)
print(s)

# 删除不存在的元素会报错
#s.remove(4)

# set 中只能放入不可变对象
l = []
#s.add(l)

# tuple 是不可变对象，但 tuple 中若包含 list 则不再是不可变对象
s.add((1,2,3))
#s.add((1,[2,3]))

