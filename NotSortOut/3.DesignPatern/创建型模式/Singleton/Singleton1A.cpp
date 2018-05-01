//线程安全的懒汉式单例模式
#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton* getInstance() {
		lock(); //加锁，保证m_instance确定时间内只能被一个线程访问
		if(nullptr == m_instance) {
			m_instance = new Singleton();
		}
		unlock();//解锁
		return m_instance;
	}
private:
	Singleton() {
		count++;
        cout << "实例化了" << count << "个对象."　<< endl;
	}

	int count = 0;

	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

int main(int argc, char* argv[]) {
	Singleton::getInstance();
	Singleton::getInstance();
}