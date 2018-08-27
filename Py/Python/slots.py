#!/usr/bin/env python3
#给实例绑定属性
class Student(object):
    pass

s = Student()
s.name = 'Michael'
print(s.name)

#给实例绑定方法
def set_age(self,age):
    self.age = age

from types import MethodType
s.set_age = MethodType(set_age,s)
s.set_age(25)
print(s.age)

#给类绑定方法，对所有实例有效
def set_score(self,score):
    self.score = score
# 动态绑定允许在程序运行时动态地给类添加功能
Student.set_score = set_score
s.set_score(100)
print(s.score)

# __slots__ 给类的实例的属性绑定作限制
class Student_2(object):
    __slots__ = ('name','age')
s = Student_2()
s.name = 'Michael'
s.age = 25
#不在 slots 中的属性进行绑定将报错
#s.score = 100

# __slots__ 的限定对子类不起作用，除非子类中也定义 __slots__
class GraduateStudent(Student_2):
    pass
g = GraduateStudent()
g.score = 100

# 子类允许定义的属性是自身的 __slots__ 加上父类的 __slots__

