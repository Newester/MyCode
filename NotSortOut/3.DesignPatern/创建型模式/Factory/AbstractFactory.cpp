/*
**抽象工厂模式：提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类
**
**
*/
#include <iostream>

using namespace std;

class AbstractProduct1 {
public:
	virtual ~AbstractProduct1() = 0;
	virtual void operation() = 0;
protected:
	AbstractProduct1() {
		cout << "AbstractProduct1()... " << endl;
	}
};
AbstractProduct1::~AbstractProduct1() {
	cout << "~AbstractProduct1()... " << endl;
}

class Product1A : public AbstractProduct1 {
public:
	Product1A() {
		cout << "Product1A()... " << endl;
	}
	virtual void operation() {}
	virtual ~Product1A() {
		cout << "~Product1A()... " << endl;
	}
};

class AbstractProduct2
{
public:
	~AbstractProduct2() = 0;
	virtual void operation() = 0;
protected:
	AbstractProduct2() {
		cout << "AbstractProduct2()... " << endl;
	}
};
AbstractProduct2::~AbstractProduct2() {
	cout << "~AbstractProduct2()... " << endl;
}


class Product2A : public AbstractProduct2 {
public:
	Product2A() {
		cout << "Product2A()... " << endl;
	}
	virtual void operation() {}
	virtual ~Product2A() {
		cout << "~Product2A()... " << endl;
	}
};

class Product1B : public AbstractProduct1 {
public:
	Product1B() {
		cout << "Product1B()... " << endl;
	}
	virtual void operation() {}
	virtual ~Product1B() {
		cout << "~Product1B()... " << endl;
	}
};

class Product2B : public AbstractProduct2 {
public:
	Product2B() {
		cout << "Product2B()... " << endl;
	}
	virtual void operation() {}
	virtual ~Product2B() {
		cout << "~Product2B()... " << endl;
	}
};

class AbstractFactory
{
public:
	virtual ~AbstractFactory() = 0;
	virtual AbstractProduct1* CreateProduct1() = 0;
	virtual AbstractProduct2* CreateProduct2() = 0;
protected:
	AbstractFactory() {
		cout << "AbstractFactory()... " << endl;
	}
};
AbstractFactory::~AbstractFactory() {
	cout << "~AbstractFactory()... " << endl;
}

class ConcreteFactoryA : public AbstractFactory {
public:
	ConcreteFactoryA() {
		cout << "ConcreteFactoryA()... " << endl;
	}
	~ConcreteFactoryA() {
		cout << "~ConcreteFactoryA()... " << endl;
	}
	virtual AbstractProduct1* CreateProduct1() {
		return new Product1A();
	}
	virtual AbstractProduct2* CreateProduct2() {
		return new Product2A();
	}
};

class ConcreteFactoryB : public AbstractFactory {
public:
	ConcreteFactoryB() {
		cout << "ConcreteFactoryB()... " << endl;
	}
	~ConcreteFactoryB() {
		cout << "~ConcreteFactoryB()... " << endl;
	}
	virtual AbstractProduct1* CreateProduct1() {
		return new Product1B();
	}
	virtual AbstractProduct2* CreateProduct2() {
		return new Product2B();
	}
};

int main(int argc, char* argv[]) {
	AbstractFactory* facA = new ConcreteFactoryA();
	AbstractProduct1* A1 = facA->CreateProduct1();
	AbstractProduct2* A2 = facB->CreateProduct2();

	AbstractFactory* facB = new ConcreteFactoryB();
	AbstractProduct1* B1 = facB->CreateProduct1();
	AbstractProduct2* B2 = facB->CreateProduct2();

	delete A1;
	delete A2;
	delete facA;

	delete B1;
	delete B2;
	delete facB;
}