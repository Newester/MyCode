#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

# 多重继承可以获得多个父类的所有功能
class Runable(object):
    def run(self):
        print('Running...')
class Flyable(object):
    def fly(self):
        print('Flying...')

class MagicAnimal(Runable,Flyable):
    pass

# MixIn 主线通过单一继承而来，附加功能采用多重继承添加

#多协程TCP
class MyTCPServer(TCPserver,CoroutineMixIn):
    pass