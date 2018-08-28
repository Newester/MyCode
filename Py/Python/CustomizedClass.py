#!/usr/bin/env python3

# __slots__ 用于限制类的属性值

# __len__() 让 class 作用于 len() 函数

# __str__
class Student(object):
    def __init__(self,name):
        self.name = name
print(Student('Michael'))

class Student_2(object):
    def __init__(self,name):
        self.name = name
    def __str__(self):
        return 'Student_2 object (name: %s)' % self.name

print(Student_2('Michael'))

class Student_3(object):
    def __init__(self,name):
        self.name = name
    def __str__(self):
        return 'Student_3 object (name %s)' % self.name
    __repr__ = __str__

# __iter__
# 一个类如果想被用于 for .. in 循环，需要实现 __iter__() 方法和 __next__() 方法
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1
    def __iter__(self):
        return self
    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        if self.a > 1000:
            raise StopIteration()
        return self.a
    
for n in Fib():
    print(n)

# __getitem__
#一个类如果想被当成 list 来用，需要实现 __getitem__() 方法
class Fib_2(object):
    def __getitem__(self,n):
        a, b = 1, 1
        for x in range(n):
            a, b = b, a + b
        return a

f = Fib_2()
print(f[0],f[1],f[2])

# 要实现切片的功能，还需要做判断
class Fib_3(object):
    def __getitem__(self,n):
        if isinstance(n,int):
            a, b = 1, 1
            for x in range(n):
                a, b = b, a + b
            return a
        if isinstance(n, slice):
            start = n.start
            stop = n.stop
            if start is None:
                start = 0
            a, b = 1, 1
            L = []
            for x in range(start,stop):
                L.append(a)
                a, b = b, a + b
            return L
        
f = Fib_3()
print(f[0:5])

# 除以上外还有 __self__() 方法、 __delitem__() 方法，用于把对象当做 list 或者 dict 来赋值，或者删除某个元素

# __getattr__ 如果没有某个属性，将调用这个函数尝试获得某个属性
class Student_4(object):
    def __init__(self,name):
        self.name = name
    def __getattr__(self,attr):
        if attr == 'score':
            return 99
        if attr == 'age':
            return lambda: 26
s = Student_4('Michael')
print(s.name,s.score,s.age())

# Restful API
class Chain(object):
    def __init__(self,path=''):
        self._path = path
    def __getattr__(self, path):
        return Chain('%s/%s' % (self._path, path))
    def __str__(self):
        return self._path
    __repr__ = __str__

print(Chain().status.user.timeline.list)

# __call__ 定义这个方法直接对实例进行调用
class Student_5(object):
    def __init__(self, name):
        self.name = name
    def __call__(self):
        print('My name is %s.' % self.name)

s = Student_5('Michael')
s()

# __call__() 还可以传递参数，也就是说可以把类的实例（对象）当做函数，把函数当做对象
#通过 callable() 函数可以判断一个对象是否为可调用对象
