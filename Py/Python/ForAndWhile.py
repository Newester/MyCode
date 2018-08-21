#!/usr/bin/env python3
names = ['Michael','Bob','Tracy']
for name in names:
    print(name)

sum = 0
for x in [1,2,3,4,5,6,7,8,9,10]:
    sum = sum + x
print(sum)

print(list(range(5)))

sum = 0
for x in range(101):
    sum = sum + x
print(sum)

sum = 0
n = 99
while n > 0:
    sum = sum + n
    n = n - 2
print(sum)

L = ['Bart','Lisa','Adam']
for name in L:
    print("Hello, %s" % name)


n = 1
while n <= 100:
    print(n)
    n = n + 1
print('END')

n = 1
while n <= 100:
    if n > 10:
        break
    print(n)
    n = n + 1
print('END')

n = 0
while n < 10:
    n = n + 1
    if n % 2 == 0:
        continue
    print(n)

# break 语句在循环过程中直接退出循环
# continue 提前结束本轮循环直接开启下一轮循环