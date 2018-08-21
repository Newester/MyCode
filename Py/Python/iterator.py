#!/usr/bin/env python3

# 可用于 for 循环的数据类型（ Iterable 对象）有
#     集合数据类型： list tuple dict set str 等
#     generator & generator function（带有 yield 关键字）

# 迭代器 Iterator 可被 next() 调用并不断返回下一个值的对象
# 生成器都是 Iterator 对象，Iterable 对象不一定是 Iterator 对象
# list dict str 等 Iterable 对象可使用 iter() 函数转化为 Iterator 对象
from collections import Iterable,Iterator
print(isinstance([],Iterable))
print(isinstance([],Iterator))
print(isinstance(iter([]),Iterator))


# python 的 Iterator 实际上是数据流， Iterator 的计算是惰性的，只有需要返回下一个数据时才进行计算

# python 的 for 循环本质是通过不断调用 next() 来实现
for x in [1,2,3,4,5]:
    print(x)

it = iter([1,2,3,4,5])
while True:
    try:
        x = next(it)
        print(x)
    except StopIteration:
        break