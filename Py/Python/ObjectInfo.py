#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

# type()
print(type(123))
print(type('str'))
print(type(None))
print(type(abs))

print(type(123)==int)
print(type(123)==type('123'))

#判断一个对象是不是函数
import types
def fn():
    pass

print(type(fn)==types.FunctionType)
print(type(abs)==types.BuiltinFunctionType)
print(type(lambda x:x)==types.LambdaType)
print(type(x for x in range(10))==types.GeneratorType)

# isinstance() 判断变量是否为某种类型
# 当变量确为某种类型或者其父系类型的一种，返回 True
#可以判断是否为某些类型中的一种
print(isinstance([1,2,3],(list,tuple)))
print(isinstance((1,2,3),(list,tuple)))

# dir() 获取一个类所有的属性和方法
print(dir('ABC'))
print(len('ABC'))
print('ABC'.__len__())


# getattr() 获取属性、 setattr() 设置属性、 hasattr() 判断是否存在某种属性
class MyObject(object):
    def __init__(self):
        self.x = 9
    def power(self):
        return self.x * self.x

obj = MyObject()

print(hasattr(obj,'x'))
print(hasattr(obj,'y'))
setattr(obj,'y',19)
print(getattr(obj,'y'))

#试图获取一个不存在的属性会报错
#getattr(obj,'z')
#可以传入一个默认参数，如果属性不存在返回默认值
print(getattr(obj,'z',404))


#可以获取对象的方法
print(hasattr(obj,'power'))
fn = getattr(obj,'power')
print(fn)
print(fn())