#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <iostream>

using namespace std;

class Component {
public:
	virtual ~Component() {}
	virtual void Operation() {}

protected:
	Component() {}
};

class ConCreteComponent : public Component {
public:
	ConCreteComponent() {}
	~ConCreteComponent() {}
	void Operation() {
		std::cout << "ConCreteComponent Operation() ..." << endl;
	}
};

class Decorator : public Component {
public:
	Decorator(Component* com) {
		this->m_com = com;
	}
	virtual ~Decorator() {
		delete m_com;
	}
	void Operation() {}

protected:
	Component* m_com;
};

class ConcreteDecorator : public Decorator {
public:
	 ConcreteDecorator(Component* com) : Decorator(com) {} 
	~ ConcreteDecorator() {}
	void Operation() {
		m_com->Operation();
		this->AddedBehavior();
	}
	void AddedBehavior() {
	    std::cout << "ConcreteDecorator AddedBehavior() ..." << endl;
	}
	
};

int main(int argc, char* argv[]) {
	Component* com = new ConCreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();
	delete dec;
	return 0;
}

#endif // __DECORATOR_H__
