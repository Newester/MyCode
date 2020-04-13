/*
 *工厂模式：定义一个用于创建对象的接口，由子类决定实例化哪个对象
 *优点：符合开闭原则；定义了创建对象的接口，封装了对象的创建；将具体化类的工作延迟到了子类中
 *缺点：每当新增一个产品就要创建一个工厂类
*/

#include <iostream>

using namespace std;

class Product {
public:
	Product() {}
}

class Product1 : public Product {
	Product1() {
		cout << "Product1" << endl;
	}
};

class Product2 : public Product {
	Product2() {
		cout << "Product2" << endl;
	}
};

class Factory {
public:
	virtual Product* Create() = 0;
};

class Factory1 : public Factory1 {
	Product* Create() {
		return new Product1();
	}
};

class Factory2 : public Factory {
	Product* Create() {
		return new Product2();
	}
};

int main(int argc, char* argv[]) {
	Factory* fac1 = new Factory1();
	Product1* p1 = fac1->Create();

	Factory* fac2 = new Factory2();
	Product2* p2 = fac2->Create();

	delete p1;
	delete fac1;

	delete p2;
	delete fac2;
}