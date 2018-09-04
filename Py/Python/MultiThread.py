#!/usr/bin/env python3
# _*_ coding:utf-8 _*_
# python 的线程是真正的 Posix Thread
# python 模块 _thread 和 threading （对 thread 进行封装）
import time,threading
#新线程执行的代码
def loop():
    print('thread %s  is running...' % threading.current_thread().name)
    n = 0
    while n < 5:
        n = n + 1
        print('thread %s >>> %s' % (threading.current_thread().name, n))
        time.sleep(1)
    print('thread %s ended.' % threading.current_thread().name)

print('thread %s is running...' % threading.current_thread().name)
t = threading.Thread(target=loop,name='LoopThread')
t.start()
t.join()
print('thread %s ended.' % threading.current_thread().name)
# threading.current_thread() 函数 --> 返回当前线程的实例
# 主线程的名字叫 MainThread ，子线程的名字创建时指定，不指定则为 Thread-1,Thread-2,...

# Lock 防止资源竞争
import time, threading

balance = 0

def change_it(n):
    global balance
    balance = balance + n
    balance = balance - n

def run_thread(n):
    for i in range(10000000):
        change_it(n)

t1 = threading.Thread(target=run_thread,args=(5,))
t2 = threading.Thread(target=run_thread,args=(8,))

t1.start()
t2.start()

t1.join()
t2.join()

print(balance)

lock = threading.Lock()
balance = 0

def run_thread_2(n):
    for i in range(100000):
        lock.acquire()
        try:
            change_it(n)
        finally:
            lock.release()
# 单个线程同时执行 lock.acquire() 时只有一个获得锁，其余线程必须等待
# 获得锁一定要释放，否则将导致死锁
# 多个线程持有多个锁，当存在需要互相等待对方的锁时也将出现死锁

# python 多线程不能多核并行 由于 pyhton 解释器有个GIL锁（Global Interpreter Lock，全局解释器锁） 
# python 线程执行前必须获取 GIL 锁，每执行100条字节码释放锁
# python 进程有各自独立的GIL锁，互不影响，能够多核并行

