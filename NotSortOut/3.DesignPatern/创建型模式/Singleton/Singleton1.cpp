//懒汉式单例模式,需要对象时才创建对象，非线程安全

#include <iostream>

using namespace std;

class Singleton {
public:
	//1.公有静态方法获取唯一实例；全局可访问，当实例不存在时创建实例，实例存在只返回指向实例的指针。
	static Singleton* getInstance() {
		if(nullptr == m_instance) {
			m_instance = new Singleton();
		}
		return m_instance;
	}

private:
	//2.构造函数私有化，禁止外部调用
	Singleton() {
		count++;
		count << "实例化了" << count << "个对象." << endl; 
	}
	int count = 0;
	//3.指向自身唯一实例的指针，也是私有的；保证实例的唯一
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

int main(int argc, char* argv[]) {
	Singleton::getInstance();
	Singleton::getInstance();
}
