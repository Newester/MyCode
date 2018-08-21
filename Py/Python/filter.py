#!/usr/bin/env python3

# filter() 用于过滤序列
# filter() 把传入的函数依次作用于每个元素根据返回值是 True 还是　Flase 决定保留还是丢弃该元素

#在一个 list 删掉偶数只保留奇数

def is_odd(n):
    return n % 2 == 1
print(list(filter(is_odd,[1,2,3,4,5,6,7,8,9,0])))


#把一个序列中的空字符串删掉

def not_empty(s):
    return s and s.strip()

print(list(filter(not_empty,['A','B',None,'C',''])))

# filter() 函数返回的是一个 Iterator ，是一个惰性序列
#要强迫 filter() 完成计算结果，需要用 list() 获得所有结果并返回 list


#用 fliter() 求素数（埃式筛法）

def odditer():
    n = 1
    while True:
        n = n + 2
        yield n

def filterprime(n):
    return lambda x: x % n > 0

def prime():
    yield 2
    it = odditer()
    while True:
        n = next(it)
        yield n
        it = filter(filterprime(n),it)

for n in prime():
    if n < 100:
        print(n)
    else:
        break

def nums():
    n = 1
    while True:
        n = n + 1
        yield n

def filterpalindrome(n):
    s = str(n)
    for i in range(len(s)):
        if s[i] != s[-1-i]:
            return False
    return True


def palindrome():
        yield 2
        it = nums()
        while True:
            n = next(it)
            yield n
            it = filter(filterpalindrome,it)


for n in palindrome():
    if n < 1000:
        print(n)
    else:
        break




