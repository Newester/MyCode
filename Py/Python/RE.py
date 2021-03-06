#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

#正则表达式 -- 匹配字符串 用一种描述性的语言定义一个规则，凡是符合规则的字符串则认为是合法的
# \d 匹配一个数字 \w 匹配一个字母或数字 . 匹配任意字符 * 表示任意个字符 + 至少一个字符 ？ 0个或者1个字符 {n} n个字符 {n,m} n~m 个字符
# \s 匹配一个空格 [] 指定范围 | 表示匹配二者之一  ^ 表示行的开头 $ 表示行的结束

# re 模块
# 建议使用python的 r 字符串，这样不用考虑转义的问题
import re
print(re.match(r'^\d{3}\-\d{3,8}$', '010-12345'))
re.match(r'^\d{3}\-\d{3,8}$','010 12345')
# match() 方法判断字符串是否匹配，如果匹配成功返回一个 match 对象，否则返回 None
test = '用户输入的字符串'
if re.match(r'正则表达式',test):
    print('OK')
else:
    print('Failed')

# 切分字符串
print('a b      c'.split(' '))
# 正则表达式切分字符串
print(re.split(r'\s+','a b    c'))


# 分组 用 ()可以提取字符串的子串
m = re.match(r'^(\d{3})-(\d{3,8})$','010-12345')
print(m)
print(m.group(0))
print(m.group(1))
print(m.group(2))
# group(0) 是原始字符串

# 匹配所有时间
t = '19:05:30'
m = re.match(r'^(0[0-9]|1[0-9]|2[0-3]|[0-9])\:(0[0-9]|1[0-9]|2[0-9]|3[0-9]|4[0-9]|5[0-9]|[0-9])\:(0[0-9]|[0-9]|2[0-9]|3[0-9]|4[0-9]|5[0-9]|[0-9])$',t)
print(m.groups())

#正则表达式有时也无法完全验证，比如匹配日期，这时要配合程序一起验证

# 贪婪匹配 -- 正则匹配默认是贪婪匹配，尽可能匹配多的字符
print(re.match(r'^(\d+?)(0*)$','102300').groups())


# 编译 -- re 模块先编译正则表达式，再用编译好的正则表达式取匹配字符串；正则表达式本身不合法，编译过程会报错
# 可以预编译好正则表达式，以后就可以直接拿来用
re_telephone = re.compile(r'^(\d{3})-(\d{3,8})$')
print(re_telephone.match('010-12345').groups())

# practice

def name_of_email(addr):
    res = re.match(r'^(\w[\w|-|_]*)@(\w+).([A-za-z]+)$',addr)
    if res:
        return res.group(0)
    else:
        return None
assert(name_of_email('hello@qq.com')) == 'hello@qq.com'
print('OK')



