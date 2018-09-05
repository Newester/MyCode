#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

# 多线程环境下每个线程都有自己的数据，这些数据最好使用局部变量
# 但是局部变量也有问题，就是函数调用的时候传参很麻烦
def Student(name):
    def __init__(self):
        self.name = name

def process_student(name):
    std = Student(name)
    do_task_1(std)
    do_task_2(std)

def do_task_1(std):
    #do_subtask_1(std)
    pass
def do_task_2(std):
    #do_subtask_2(std)
    pass
# 每一层调用都要传参，相当麻烦

# 一种解决方案是用一个全局的 dict 存放参数
global_dict = {}

def std_thread(name):
    std = Student(name)
    global_dict[threading.current_thread()] = std
    do_task_1_2()
    do_task_2_2()

def do_task_1_2():
    std = global_dict[threading.current_thread()]
    pass
def do_task_2_2():
    std = global_dict[threading.current_thread()]

# 更优雅地方案是使用 ThreadLocal
import threading

local_school = threading.local()

def process_student_2():
    #获取当前线程关联的 student 
    std = local_school.student
    print('Hello,%s(in %s)' % (std,threading.current_thread().name))

def process_thread(name):
    local_school.student = name
    process_student_2()

t1 = threading.Thread(target=process_thread,args=('Alice',),name='Thread-A')
t2 = threading.Thread(target=process_thread,args=('Bob',),name='Thread-B')
t1.start()
t2.start()
t1.join()
t2.join()

