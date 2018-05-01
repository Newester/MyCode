//自动内存回收的懒汉式单例模式

class Singleton {
public:
	static Singleton* getInstance() {
		if(nullptr == m_instance) {
			m_instance = new Singleton();
		}
		return m_instance;
	}
	class Garbage {
	public:
    	~Garbage() {
    		if(nullptr != Singleton::m_instance) {
    			cout << "唯一单例被析构." << endl;
    			delete Singleton::m_instance;
    		}
    	}
    };
private:
	static Garbage gc;
	static Singleton* m_instance;

	Singleton() {
		cout << "调用单例构造函数" << endl;
	}
	~Singleton() {
		cout << "调用了单例的析构函数"　<< endl;
	}
};

Singleton::Garbage Singleton::garbage;
Singleton* Singleton::m_instance = nullptr;

int main(int argc, char* argv[]) {
	Singleton* a = Singleton::getInstance();
	Singleton* b = Singleton::getInstance()

	cout << a==b << endl;
}

