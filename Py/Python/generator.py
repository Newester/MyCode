#!/usr/bin/env python3
g = (x*x for x in range(1,11))
print(g)
print(next(g))

for n in g:
    print(n)

# 打印斐波那契数列
def fib(max):
    n,a,b = 0,0,1
    print('start')
    while n < max:
        print(b)
        a,b = b,a+b
        n = n + 1
    print('done')

fib(10)

# 如果一个函数中含有 yield 关键字，这个函数就变成了一个 generator
def fib_2(max):
    n,a,b = 0,0,1
    while n < max:
        yield b # here
        a,b = b,a+b
        n = n + 1
    return 'done'

# generator 每次调用 next()执行，遇到 yeild 返回，再次执行时会从上次返回的地方开始执行

def odd():
    print('step 1')
    yield 1
    print('step 2')
    yield(3)
o = odd()
next(o)
next(o)
#越界会报错
# next(o)

# for 循环调用 generator
# 这种调用拿不到 generator 的返回值
for n in fib_2(7):
    print(n)

# 获取 generator 返回值需要捕获 StopIteration 异常
g = fib_2(8)
while True:
    try:
        x = next(g)
        print('g:',x)
    except StopIteration as e:
        print('Generator return value:',e.value)
        break

# practice 打印杨辉三角
def triangles(row):
    L = [1]
    n = row
    i = 0
    while n > 0:
        yield L
        i = i + 1
        l = len(L)
        if l == 1:
            L.append(1)
        else:
            p = [ L[k-1]+L[k] for k,v in enumerate(L) if k > 0 and k < l]
            p.insert(0,1)
            p.append(1)
            L = p
        n = n - 1


for x in triangles(5):
    print(x)

# generator 实际返回一个 generator 对象

