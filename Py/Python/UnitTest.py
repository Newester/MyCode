#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

# TDD : Test-Driven Development -- 测试驱动开发
# 1、编写测试用例放到一个测试模块里
# 2、修改代码后，运行单元测试能否通过

class Dict(dict):
    def __init__(self, **kv):
        super().__init__(**kv)
    def __getattr__(self,key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Dict' object has no attribute '%s'" % key)
    def __setattr__(self,key,value):
        self[key] = value
d = Dict()


#如下代码应当放在另一个文件，并引用测试的模块
import unittest

class TestDict(unittest.TestCase):
    def test_init(self):
        d = Dict(a = 1, b = 'test')
        self.assertEqual(d.a, 1)
        self.assertEqual(d.b, 'test')
        self.assertTrue(isinstance(d,dict))
    def test_key(self):
        d = Dict()
        d['key'] = 'value'
        self.assertEqual(d.key, 'value')
    def test_attr(self):
        d = Dict()
        d.key = 'value'
        self.assertTrue('key' in d)
        self.assertEqual(d['key'], 'value')
    def test_keyerror(self):
        d = Dict()
        with self.assertRaises(KeyError):
            value = d['empty']
    def test_attrerror(self):
        d = Dict()
        with self.assertRaises(AttributeError):
            value = d.empty
#以 test 开头的才是测试方法，其他并不是

# setUp() 和 tearDown() ，在调用每一个测试方法的前后执行
    def setUp(self):
        print('setUp...')
    def tearDown(self):
        print('tearDown...')


#运行单元测试
# 方法 1 : 加上如下代码，python mytest.py
#if __name__ == '__main__':
#    unittest.main()

# 方法 2 : 命令行参数 -m unittest

#practice 
class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def get_grade(self):
        if self.score < 0 or self.score > 100:
            raise ValueError
        if self.score >= 60 and self.score < 80:
            return 'B'
        if self.score >= 80:
            return 'A'
        return 'C'
class TestStudent(unittest.TestCase):

    def test_80_to_100(self):
        s1 = Student('Bart', 80)
        s2 = Student('Lisa', 100)
        self.assertEqual(s1.get_grade(), 'A')
        self.assertEqual(s2.get_grade(), 'A')

    def test_60_to_80(self):
        s1 = Student('Bart', 60)
        s2 = Student('Lisa', 79)
        self.assertEqual(s1.get_grade(), 'B')
        self.assertEqual(s2.get_grade(), 'B')

    def test_0_to_60(self):
        s1 = Student('Bart', 0)
        s2 = Student('Lisa', 59)
        self.assertEqual(s1.get_grade(), 'C')
        self.assertEqual(s2.get_grade(), 'C')

    def test_invalid(self):
        s1 = Student('Bart', -1)
        s2 = Student('Lisa', 101)
        with self.assertRaises(ValueError):
            s1.get_grade()
        with self.assertRaises(ValueError):
            s2.get_grade()

if __name__ == '__main__':
    unittest.main()
