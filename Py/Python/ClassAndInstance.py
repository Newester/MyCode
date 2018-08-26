#!/usr/bin/env python3

#类是抽象的模板，实例是根据类创建出来的一个个具体的对象
#每个对象都有相同的方法，但各自的数据可能不同

#类 class
class Student(object):
    pass

#实例
bart = Student()
print(bart)
print(Student)

#可以自由的给一个实例变量绑定属性
bart.name = 'Bart'
print(bart.name)

# __init__() 方法：在创建类的实例时把一些属性强制填写进去
class Student_2(object):
    def __init__(self,name,score): # __init__() 的第一参数永远是实例变量 self ，调用时不用传递它
        self.name = name
        self.score = score
    def print_score(self):
        print('%s:%s' % (self.name,self.score))

bart = Student_2('Bart',60)
print(bart.name,bart.score)
bart.print_score()

