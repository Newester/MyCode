#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton* getInstance {
		return m_instance;
	}
private:
	static Singleton* m_instance;
	Singleton() {}
};

Singleton* Singleton::m_instance = new Singleton();

int main(int argc, char* argv[]) {
	Singleton::getInstance();
	Singleton::getInstance();
}