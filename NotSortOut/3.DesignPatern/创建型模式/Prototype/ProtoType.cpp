/*
 *原型模式：一个对象再创建另外一个可定制的对象，而无需知道任何创建的细节。
 *原型模式作用：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
 *原型模式重在从自身复制自己创建新的对象，隐藏（不需知道）对象创建的细节
*/

#include <iostream>

using namespace std;

//原型基类，定义Clone接口函数
class ProtoType {
protected:
	//保护构造函数
	ProtoType() {
		cout << "ProtoType. " << endl; 
	}
public:
	virtual ProtoType* Clone() const = 0;//定义Clone接口，根据不同的派生类来实例化对象
	//抽象析构函数，方便调用基类或是子类
	virtual ~ProtoType() {
		cout << "~ProtoType()... " << endl;
	}
};

//派生类１，实现了Clone函数
class ProtoType1 : public ProtoType {
public:
	ProtoType1() {
		cout << "ProtoType1. " << endl;
	}
	~ProtoType1() {
		cout << "~ProtoType1()... " << endl;
	}
	//拷贝构造函数
	ProtoType1(const ProtoType1& cp) {
		cout << "ProtoType1 copy... " <<endl;
	}
	//定义基类的Clone接口，内部调用拷贝构造函数
	virtual ProtoType* Clone() const {
		return new ProtoType1(*this);//传入this指针，调用拷贝构造函数
	}
};

//派生类２
class ProtoType2 : public ProtoType {
public:
	ProtoType2() {
		cout << "ProtoType2. " << endl;
	}
	~ProtoType2() {
		cout << "~ProtoType2()... " << endl;
	}
	ProtoType2(const ProtoType2& ) {
		cout << "ProtoType2 copy... " << endl;
	}
	virtual ProtoType* Clone() const {
		return new ProtoType2(*this);
	}
};


int main(int argc, char* argv[]) {
	ProtoType* p1 = new ProtoType1();
	ProtoType* p2 = p1->Clone();
	cout << "----------------------" << endl;
	ProtoType* p3 = new ProtoType2();
	ProtoType* p4 = p3->Clone();
	cout << "----------------------" << endl;
	delete p1;
	delete p2;
	cout << "-----------------------" << endl;
	delete p3;
	delete p4;

}