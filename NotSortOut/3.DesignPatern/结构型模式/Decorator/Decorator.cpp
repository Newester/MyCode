/*
 *@brief 装饰模式
 *@details 装饰模式的重点在于装饰，一个功能用一个简单的类来表示装饰的职责，这个简单的类与他要装饰的对象的类提供一致的接口，这样保持了接口的一致性
 *@details 装饰模式提供了更加灵活的向对象添加职责的方式。可以用添加和分离的方法，用装饰在运行时刻增加和删除职责。装饰模式提供了一种“即用即付”的方法来添加职责。它并不试图在一个复杂的可定制的类中支持所有可预见的特征，相反，你可以定义一个简单的类，并且用装饰类给它逐渐地添加功能。可以从简单的部件组合出复杂的功能
 *@details 动态地给一个对象添加一些额外的职责
 *@details 在不影响其他对象的情况下，以动态、透明的方式给单个对象添加职责
 *@details 处理那些可以撤消的职责
 *@details 当不能采用生成子类的方法进行扩充时
*/

#include <iostream>

using namespace std;

class Component {
public:
	virtual void Operation() = 0;
};

class ConcreteComponent : public Component {
public:
	void Operation() {
		cout << "ConcreteComponent::Operation()..." << endl;
	}
};

class Decorator : public Component {
public:
	Decorator(Component *com) : m_com(com) {}
	void Operation() {
		if(nullptr != m_com) {
			m_com->Operation();
		}
	}
private:
	Component* m_com;
};

class DecoratorA : public Decorator {
public:
	DecoratorA(Component *com) : Decorator(com) {}
	void Operation() {
		AddBehavior();
		Decorator::Operation();
	}
	void AddBehavior() {
		cout << "DecoratorA::AddedBehavior..." << endl;
	}

};

class DecoratorB : public Decorator {
public:
	DecoratorB(Component *com) : Decorator(com) {}
	void Operation() {
		AddBehavior();
		Decorator::Operation();
	}
	void AddBehavior() {
		cout << "DecoratorB::AddedBehavior..." << endl;
	}

};

int main(int argc, char* argv[]) {
	Component* com = new ConcreteComponent();
	Decorator* dec = new Decorator(com);
	dec->Operation();
	Decorator* decA = new DecoratorA(com);
	decA->Operation();
	Decorator* decB = new DecoratorB(decA);
	decB->Operation();

	delete decB;
	delete decA;
	delete dec;
	delete com;
}
