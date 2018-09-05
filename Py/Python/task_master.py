#!/usr/bin/env python3
# _*_ coding: utf-8 _*_
# Process可以分布到多台机器上
# multiprocessing 的子模块 managers 支持把多进程分不到多台机器上
# managers 可以通过网络将进程间通讯的 Queue 暴露出去
import random, time, queue
from multiprocessing.managers import BaseManager

task_queue = queue.Queue()
result_queue = queue.Queue()

class QueueManager(BaseManager):
    pass

QueueManager.register('get_task_queue', callable=lambda: task_queue)
QueueManager.register('get_result_queue',callable=lambda: result_queue)
manager = QueueManager(address=('',5000),authkey=b'liaoxuefeng')
manager.start()
task = manager.get_task_queue()
result = manager.get_result_queue()

for i in range(10):
    n = random.randint(0,1000)
    print('task put %d...' % n)
    task.put(n)

print('try get result...')
for i in range(10):
    r = result.get(timeout=10)
    print('result: %s' % r)

manager.shutdown()
print('master exit.')

# 分布式多进程要求不能直接对 task_queue 进行操作，必须通过 manager.get_task_queue() 的封装
