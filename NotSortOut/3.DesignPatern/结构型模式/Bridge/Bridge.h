/*
 *＠brief　桥接模式，将系统的抽象与实现相分离，使得两方面可以独立的变化，提高内聚，降低耦合
 *@details 使用组合的方式分离抽象与实现，实现彻底的解耦
*/

#include <iostream>

using namespace std;

//抽象的基类
class Abstraction {
public:
	virtual ~Abstraction() {}
	virtual void Operation() = 0;
protected:
	Abstraction() {}

};
void Abstraction::Operation() {}


//实现的基类
class AbstractionImp {
public:
	virtual ~AbstractionImp() {}
	virtual void Operation() = 0;
protected:
	Abstraction() {
		cout << "AbstractionImp()... " << endl;
	}

};
void AbstractionImp::Operation() {}

//派生抽象类Ａ
class RefinedAbstractionA : public Abstraction {
public:
	RefinedAbstractionA(AbstractionImp* imp) {
		m_imp = imp;
	}
	~RefinedAbstractionA() {}
	void Operation() {
		cout << "RefinedAbstractionA m_imp->Operation()... " << endl;
		m_imp->Operation();
	}
private:
	AbstractionImp* m_imp;

};

//派生抽象类Ｂ
class RefinedAbstractionB : public Abstraction {
public:
	RefinedAbstractionB(AbstractionImp* imp);
	~RefinedAbstractionB() {}
	void Operation() {
		cout << "RefinedAbstractionB m_imp->Operation()... " << endl;
		m_imp->Operation();
	}
private:
	AbstractionImp* m_imp;

};

//派生实现类A
class ConcreteAbstractionImpA : public AbstractionImp {
public:
	ConcreteAbstractionImpA() {
		cout << "ConcreteAbstractionImpA()... " << endl;
	}
	~ConcreteAbstractionImpA() {}
	void Operation() {
		cout << "ConcreteAbstractionImpA::Operation()... " << endl;
	}

};

//派生实现类B
class ConcreteAbstractionImpB : public AbstractionImp {
public:
	ConcreteAbstractionImpB() {
		cout << "ConcreteAbstractionImpB()... " << endl;
	}
	~ConcreteAbstractionImpB() {}
	void Operation() {
		cout << "ConcreteAbstractionImpB::Operation()... " << endl;
	}
};


int main(int argc, char* argv[]) {
	AbstractionImp *impA = new ConcreteAbstractionImpA();
	Abstraction *absA = new RefinedAbstractionA(impA);
	absA->Operation();

	cout << "-------------------------------" << endl;

	AbstractionImp *impB = new ConcreteAbstractionImpB();
	Abstraction *absB = new RefinedAbstractionB(impA);
	absB->Operation();
}


