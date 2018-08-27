#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

#不要把属性直接暴露出去，而应该进行封装，限定属性值的范围，检查参数合法性
class Student(object):
    def get_score(self):
        return self._score
    def set_score(self,value):
        if not isinstance(value,int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self._score = value
s = Student()
s.set_score(60)
print(s.get_score())
# 现在不能随便随意地给属性赋值了
#s.set_score(9999)

# @property 装饰器可以方便地把一个方法变成属性调用
class Student_2(object):
    @property
    def score(self):
        return self._score
    @score.setter
    def score(self,value):
        if not isinstance(value,int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100')
        self._score = value
s = Student_2()
s.score = 60
print(s.score)

#只定义 getter 方法，不定义 setter 方法，就是一个只读属性
class Student_3(object):
    @property
    def birth(self):
        return self._birth
    @birth.setter
    def birth(self,value):
        self._birth = value
    @property
    def age(self):
        return 2018 - self._birth

# practice 
class Screen(object):
    
    @property
    def width(self):
        return self._width
    @width.setter
    def width(self,value):
        if not isinstance(value,int):
            raise ValueError('Screen width must be an integer!')
        if value < 0:
            raise ValueError('Screen width must be greater than 0!')
        self._width = value
    
    @property
    def height(self):
        return self._height
    @height.setter
    def height(self,value):
        if not isinstance(value,int):
            raise ValueError('Screen height must be an integer!')
        if value < 0:
            raise ValueError('Screen height must be greater than 0!')
        self._height = value
    
    @property
    def resolution(self):
        return self._width*self._height
    
