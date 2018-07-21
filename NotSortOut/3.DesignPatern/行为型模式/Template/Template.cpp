/**
 *@brief 模板方法模式
**/

#include <iostream>

using namespace std;

class AbstractClass
{
public:
	~AbstractClass() {}
	void TemplateMethod() {
		this->AbstractMethodImp();
	}
	virtual void AbstractMethodImp() = 0;
protected:
	AbstractClass() {}
	
};


class ConcreteClassA : public AbstractClass {
public:
	ConcreteClassA() {}
	~ConcreteClassA() {}
	void AbstractMethodImp() {
		cout << "ConcreteClassA::AbstractMethodImp()... " << endl;
	}
};

class ConcreteClassB : public AbstractClass {
public:
	ConcreteClassB() {}
	~ConcreteClassB() {}
	void AbstractMethodImp() {
		cout << "ConcreteClassB::AbstractMethodImp()... " << endl;
	}
};


int main(int argc, char const *argv[])
{
	AbstractClass* ca = new ConcreteClassA();
	ca->TemplateMethod();

	AbstractClass* cb = new ConcreteClassB();
	cb->TemplateMethod();
	
	return 0;
}