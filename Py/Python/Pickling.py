#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

#序列化是指把变量从内存中变成可存储或传输的过程
#序列化之后就可以把序列化后的内容写入磁盘或者通过网络传输到别的机器上
#把变量内容从序列化的对象重新读到内存里称为反序列化 unpicking

import pickle
d= dict(name='Bob', age=20, score=88)
print(pickle.dumps(d))

# pickle.dump() 直接将对象序列化并写入类文件对象
#f = open('dump.txt','wb')
#pickle.dump(d,f)
#f.close()

# 反序列化
f = open('dump.txt','rb')
d = pickle.load(f)
f.close()
print(d)

#JSON 和内置 json 模块

'''
JSON       Python
{}         dict
[]         list
"string"   str
1234.56    int/float
true/false True/False
null       None
'''

# Python --> JSON
import json
d = dict(name='Bob', age=20, score=88)
print(json.dumps(d))
f = open('dump.json','w')
json.dump(d,f)
f.close()
# JSON --> Python
json_str = '{"age": 20, "score": 88, "name": "Bob"}'
print(json.loads(json_str))
f = open('dump.json','r')
d = json.load(f)
f.close()
print(d)

# 用 class 表示对象然后序列化
#定义类
class Student(object):
    def __init__(self, name, age, score):
        self.name = name
        self.age = age
        self.score = score
s = Student('Bob', 20, 88)
# 定义将对象转化为 可JSON化对象的方法
def Student2dict(std):
    return {
        'name': std.name,
        'age': std.age,
        'score': std.score
    }
print(json.dumps(s, default=Student2dict))
print(json.dumps(s,default=lambda obj: obj.__dict__))
def dictToStudent(d):
    return Student(d['name'],d['age'],d['score'])
json_str = '{"age": 20, "score": 88, "name": "Bob"}'
print(json.loads(json_str,object_hook=dictToStudent))

obj = dict(name='小明', age=20)
s = json.dumps(obj,ensure_ascii=True)
print(s)