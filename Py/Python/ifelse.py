#!/usr/bin/env python3

age = 20
if age >= 18:
    print("your age is",age)
    print('adult')

age = 3
if age >= 18:
    print('your age is',age)
    print('adult')
else:
    print('your age is',age)
    print('teenager')

age = 3
if age >= 18:
    print('adult')
elif age >= 6:
    print('teenager')
else:
    print('kid')

# if 语句 执行是从上往下，如果在某个判断上为 True ,剩下的 elif else都不会执行   
age = 20
if age >= 6:
    print('teenager')
elif age >= 18:
    print('adult')
else:
    print('kid')

#当 x 为非零的数、非空的字符串、非空的 list 等，判断为True
x = 10
if x:
    print('True')

# input() 返回的数据类型是 str
s = input('birth:')
birth = int(s)
if birth < 2000:
    print('00前')
else:
    print('00后')

height = 1.75
weight = 80.5

bmi = weight / (height*height)

if bmi < 18.5:
    print('过轻')
elif bmi >= 18.5 and bmi < 25:
    print('正常')
elif bmi >= 25 and bmi < 28:
    print('过重')
elif bmi >= 28 and bmi <= 32:
    print('肥胖')
else:
    print('严重肥胖')

