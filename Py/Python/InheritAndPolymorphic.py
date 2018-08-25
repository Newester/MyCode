#!/usr/bin/env python3

#基类
class Animal(object):
    def run(self):
        print('Animal is running...')
#继承
class Dog(Animal):
    pass
animal = Animal()
animal.run()
dog = Dog()
dog.run()
print(isinstance(dog,Dog))
print(isinstance(dog,Animal))
print(isinstance(animal,Dog))
#多态
class Cat(Animal):
    def run(self):
        print('Cat is running...')
    def eat(self):
        print('Cat is eating...')

cat = Cat()
cat.run()
cat.eat()

#动态语言的“鸭子类型” ——　只要看起来像鸭子，那就是只鸭子
#不要求严格的继承体系，只要有某种对象对应的方法，就可以当做某种对象来用

