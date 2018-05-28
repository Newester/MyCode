/*
 *简单工厂模式，又名静态工厂方法模式
 *一个工厂类根据传入的参数，动态决定应该创建哪一类产品的实例
 *缺陷：每当新增产品时都需要修改工厂类，违反了开闭原则
*/

#include <iostream>

using namespace std;

class Product {
public:
	Product() {}
};

class Product1 : public Product {
public:
	Product1() {
		cout << "Product1" << endl;
	}
};

class Product2 : public Product {
public:
	Product2() {
		cout << "Product2" << endl;
	}
};

class SimpleFactory
{
public:
	Product* Create(int i) {
		switch(i) {
		case 1:
			return new Product1();
		case 2:
			return new Product2();
		default:
			break;

		}
	}	
};

int main(int argc, char* argv[]) {
	SimpleFactory* fac = new SimpleFactory();
	Product1* p1 = fac->Create(1);
	Product2* p2 = fac->Create(2);

	delete p1;
	delete p2;
	delete fac;
}