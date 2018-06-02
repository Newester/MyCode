/*
 *@brief 适配器模式，将一个类的接口转换成客户希望的另一个接口，让原来接口不兼容的那些类可以一起工作
 *＠details 当系统的数据与行为都正确，但接口不符时，考虑适配器模式；
 *@details 当希望复用一些现存的类，但接口与复用环境要求不一致时；考虑适配器模式；
 *＠details 适配器模式分为类适配器模式与对象适配器模式.
*/

#include <iostream>

using namespace std;

/*
 *@brief 目标接口类，客户需要的接口
*/
calss Target {
public:
	Target()　{}
	virtual ~Target() {}

	//定义标准的接口
	virtual void Request() {
		cout << "Target::Request()... " << endl;
	}
};

/*
 *@brief 需要适配的类
*/
class Adaptee {
public:
	Adaptee() {}
	~Adaptee() {}
	void SpecificRequest() {
		cout << "Adaptee::SpecificRequest()... " << endl;
	}
};

/*
 *@brief 类适配器模式，适配器类
 *@details 接口继承Target类，实现继承Adaptee类
*/
class Adapter : public Target, private Adaptee {
public:
	Adapter() {}
	~Adapter() {}

	//实现Target类定义的Request接口
	virtual void Request() {
		cout << "Adapter::Request()... " << endl;
		this->SpecificRequest();
	}
};

/*
 *@brief 对象适配器模式，适配器类
 *@details 采用组合的方式来实现Adaptee的复用
*/
class Adapter1 : public Target {
public:
	Adapter1(Adaptee* adaptee) {
		m_adaptee = adaptee;
	}
	Adapter1() : m_adaptee(new Adaptee) {}
	~Adapter1() {}

	//实现Target定义的Request接口
	virtual void Request() {
		cout << "Adapter1::Request()... " << endl;
		this->m_adaptee->SpecificRequest();
	}

private:
	Adaptee* m_adaptee;

};


int main(int argc, char* argv[]) {

	//类适配器模式
	Target* target = new Adapter();
	target ->Request();

	//对象适配器模式
	Adaptee* adaptee = new Adaptee();
	Target target1 = new Adapter1(adaptee);
	target1->Request();


	return 0;
}
