/**
 *@brief 观察者模式
 *@details 定义一种一对多的依赖关系，让多个观察者同时监听摸一个主题对象，这个主题对象在状态发生变化时会通知所有观察者对象，使得他们能够自动更新自己
 *@details 观察者需要注册给被观察者
**/

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Subject;

class Observer {
public:
	~Observer() {}
	virtual void Update(Subject*) = 0;
protected:
	Observer() {}
};

class ConcreteObserverA : public Observer {
public:
	ConcreteObserverA() {}
	~ConcreteObserverA() {}
	void Update(Subject* subject) {
		this->m_state = subject->GetState();
		cout << "ConcreteObserverA::Update()...,state = " << m_state << endl;
	}
private:
	string m_state;
};

class ConcreteObserverB {
public:
	ConcreteObserverB() {}
	~ConcreteObserverB() {}
	void Update(Subject* subject) {
		this->m_state = subject->GetState();
		cout << "ConcreteObserverB::Update()...,state = " << m_state << endl; 
	}
private:
	string m_state;
	
};

class Subject {
public:
	~Subject() {}
	virtual void Notify() {
		list<Observer*>::iterator it = this->m_list.begin();
		for(;it != m_list.end();++it){
			(*it)->Update(this);
		}
	}
	virtual void Attach(Observer* observer) {
		this->m_list.push_back(observer);
		cout << "Attach an observer..." << endl;
	}
	virtual void Detach(Observer* observer) {
		list<Observer*>::iterator it = find(m_list.begin(),m_list.end(),observer);
		if( it != m_list.end() ) {
			m_list->erase(it);
			cout << "Detach an observer... " << endl;
		}
	}
	virtual string GetState() {
		return this->m_state;
	}
	virtual void SetState(string state) {
		this->m_state = state;
	}
protected:
	Subject() {}
private:
	string m_state;
	list<Observer*> m_list;
};

class ConcreteSubjectA : public Subject
{
public:
	ConcreteSubjectA() {}
	~ConcreteSubjectA() {}
	
};

class ConcreteSubjectB : public Subject
{
public:
	ConcreteSubjectB() {}
	~ConcreteSubjectB() {}
	
};

int main(int argc, char* argv[]) {
	Observer* oa = new ConcreteObserverA();
	Observer* ob = new ConcreteObserverB();

	Subject* sa = new ConcreteSubjectA();
	Subject* sb = new ConcreteSubjectB();

	sa->Attach(oa);
	sa->Attach(ob);

	sa->SetState("old");
	sa->Notify();


	sa->SetState("new");
	sa->Detach(ob);

	sa->Notify();

	return 0;

}
