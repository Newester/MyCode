#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

from enum import Enum
Month = Enum('Month',('Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec'))

for name, member in Month.__members__.items():
    print(name,'=>',member,',',member.value)

# value 属性是自动赋给成员的 int 常量，默认从 1 开始

#如果需要精确地控制枚举类型，可以从 Enum 派生出自定义类
from enum import unique

# unique 装饰器检查保证没有重复值
@unique
class Weekday(Enum):
    Sun = 0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6

day1 = Weekday.Mon
print(day1)
print(Weekday.Tue)
print(day1 == Weekday.Mon)
print(day1 == Weekday.Tue)
print(Weekday(1))


# practice
class Gender(Enum):
    Male = 0
    Female = 1

class Student(object):
    def __init__(self,name,gender):
        if(isinstance(gender,Gender)):
            self.name = name
            self.gender = gender
        else:
            raise ValueError("gender must be the type of Gender.")