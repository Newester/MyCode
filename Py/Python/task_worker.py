#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

import time, sys, queue
from multiprocessing.managers import BaseManager

class QueueManager(BaseManager):
    pass
QueueManager.register('get_task_queue')
QueueManager.register('get_result_queue')

server_addr = '127.0.0.1'
print('Connect to server %s...' % server_addr)

m = QueueManager(address=(server_addr, 5000), authkey=b'liaoxuefeng')
m.connect()

task = m.get_task_queue()
result = m.get_result_queue()

for i in  range(10):
    try:
        n = task.get(timeout=1)
        print('get %d from master.' % n)
        r = '%d * %d = %d' % (n, n, n*n)
        time.sleep(1)
        print('put result %d to master...' % (n*n))
        result.put(r)
    except Queue.Empty:
        print('task queue is empty.')
print('worker exit.')