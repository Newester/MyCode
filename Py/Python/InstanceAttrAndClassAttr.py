#!/usr/bin/env python3

# 给实例绑定属性通过实例变量或者通过 self 变量
class Student(object):
    def __init__(self,name):
        self.name = name
s = Student('Bob')
s.score = 90

# 给类本身绑定一个属性
class Student_2(object):
    name = 'Student'
s = Student_2()
# 类的所有实例都可以访问类的属性
print(s.name)
print(Student_2.name)
# 实例的属性会屏蔽类的同名属性
s.name = 'Michael'
print(s.name)
# 删除实例的属性,类的属性仍保留
del s.name
print(s.name)