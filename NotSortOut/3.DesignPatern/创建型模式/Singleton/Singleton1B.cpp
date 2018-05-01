//双重锁定的懒汉式单例模式，线程安全同时可以防止过多线程阻塞
#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton* getInstance() {
		if(nullptr == m_instance) {
			//只有当m_instance为空时才上锁,当对象创建完之后锁就相当于不存在了
			lock();
			if(nullptr == m_instance) {
				m_instance = new Singleton();
			}
			unlock();
		}
		return m_instance;
	}
private:
	Singleton() {
		count++;
		cout << "实例化了"　<<count << "个对象." << endl;
	}
	int count = 0;
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

int main(int argc, char* argv[]) {
	Singleton::getInstance();
	Singleton::getInstance();
}