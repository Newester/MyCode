#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

#动态语言类的定义是在运行时动态创建的

from hello_module import Hello
h = Hello()
h.hello()
print(type(Hello))
print(type(h))

# type() 可以查看一个类型或变量的类别，class 的定义是通过 type() 函数动态创建的
# type() 既可以返回一个变量的类型，又可以创建一个新类型
def fn(self, name='world'):
    print('Hello, %s' % name)
Hello_2 = type('Hello_2',(object,),dict(hello = fn))
h = Hello_2()
h.hello()
print(type(Hello_2))
print(type(h))
#创建一个新类型 type() 要传入 class的名称，继承的父类的集合 tuple ，class的方法名称和函数绑定 dict

# metaclass 控制类的创建的行为
#先定义 metaclass ，就可以创建类，最后创建实例
class ListMetaClass(type):
    def __new__(cls,name,bases,attrs):
        attrs['add'] = lambda self,value:self.append(value)
        return type.__new__(cls,name,bases,attrs)
class MyList(list,metaclass=ListMetaClass):
    pass
L = MyList()
L.add(1)
L.add(2)
print(L)