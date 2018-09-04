#!/usr/bin/env python3

# Unix/Linux 操作系统的 fork() 调用
#调用 1 次，返回 2 次（拷贝一份到子进程执行）
import os
print('Process(%s) start...' % os.getpid())
#Only works on Unix/linux/Mac
'''
pid = os.fork()
if pid == 0:
    print('I am child process (%s) and my parent is process (%s)' %(os.getpid(),os.getppid()))
else:
    print('I am process (%s) and I created a child process (%s)' % (os.getpid(),pid))
'''
# 跨平台多进程支持
# 创建子进程时只需传递一个执行函数和函数的参数，创建一个 Process 实例，用 start() 方法启动
from multiprocessing import Process
import os
def run_proc(name):
    print('Run child process %s pid(%s)' % (name,os.getpid()))

if __name__ == '__main__':
    print('Parent process pid(%s)' % os.getpid())
    p = Process(target=run_proc,args=('test',))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')

# 进程池
from multiprocessing import Pool
import os, time, random

def long_time_task(name):
    print('Run task %s pid(%s)' % (name,os.getpid()))
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print('Task %s run %.2f seconds.' % (name,(end - start)))

if __name__ == '__main__':
    print('Parent process %s.' % os.getpid())
    p = Pool(3)
    for i in range(4):
        p.apply_async(long_time_task,args=(i,))
    print('Waiting for all subprocess done...')
    p.close()
    p.join()
    print('All subprocess done.')

    # 子进程， subprocess 控制子进程的输入输出
    import subprocess
    print('$ nslookup www.python.org')
    r = subprocess.call(['nslookup','www.python.org'])
    print('Exit code',r)

    print('$nslookup')
    p = subprocess.Popen(['nslookup'], stdin=subprocess.PIPE,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, err = p.communicate(b'set q=mx\npython.org\nexit\n')
    print(output.decode('gbk'))
    print('Exit code:', p.returncode)


# 进程间通信
# Queue , Pipes
from multiprocessing import Queue, Process
import os, time, random

# 写数据进程执行的代码:
def write(q):
    print('Process to write: %s' % os.getpid())
    for value in ['A', 'B', 'C']:
        print('Put %s to queue...' % value)
        q.put(value)
        time.sleep(random.random())

# 读数据进程执行的代码:
def read(q):
    print('Process to read: %s' % os.getpid())
    while True:
        value = q.get(True)
        print('Get %s from queue.' % value)

if __name__=='__main__':
    # 父进程创建Queue，并传给各个子进程：
    q = Queue()
    pw = Process(target=write, args=(q,))
    pr = Process(target=read, args=(q,))
    # 启动子进程pw，写入:
    pw.start()
    # 启动子进程pr，读取:
    pr.start()
    # 等待pw结束:
    pw.join()
    # pr进程里是死循环，无法等待其结束，只能强行终止:
    pr.terminate()
