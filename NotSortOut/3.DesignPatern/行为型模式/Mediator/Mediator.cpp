/**
 *@brief 中介者模式
 *@details 用一个中介对象来封装一系列的对象交互
 *@details 使各个对象B不需要显式地相互引用，从而使其耦合松散，而且可以独立地变化。   
 *@details 控制集中化将交互的复杂性变为了中介者的复杂性
 **/

#include <iostream>
#include <string>

using namespace std;

class Mediator;

class Colleague {
public:
	virtual ~Colleague() {}
	virtual void SetMediator(Mediator* mediator) {
		this->m_mediator = mediator;
	}
	virtual void SendMsg(string) = 0;
	virtual void GetMsg(string) = 0;
protected:
	Colleague(Mediator* mediator) {
		this->m_mediator = mediator;
	}
	Mediator* m_mediator;
};

class ConcreteColleagueA : public Colleague {
public:
	~ConcreteColleagueA() {}
	ConcreteColleagueA(Mediator* mediator) : Colleague(mediator) {}
	void SendMsg(string msg) {
		this->m_mediator->SendMsg(msg,this);
	}
	void GetMsg(string msg) {
		cout << "ConcreteColleagueA Recive : " << msg << endl;
	}
};

class ConcreteColleagueB : public Colleague {
public:
	~ConcreteColleagueB() {}
	ConcreteColleagueB(Mediator* mediator) : Colleague(mediator) {}
	void SendMsg(string msg) {
		this->m_mediator->SendMsg(msg,this);
	}
	void GetMsg(string msg) {
		cout << "ConcreteColleagueB Recieve: " << msg << endl;
	}
};

class Mediator {
public:
	virtual ~Mediator() {}
	virtual void SendMsg(string,Colleague*) = 0;
protected:
	Mediator() {}
};

class ConcreteMediator : public Mediator {
public:
	ConcreteMediator() {}
	~ConcreteMediator() {}
	void SetColleagueA(Colleague* ca) {
		this->m_ca = ca;
	}
	void SetColleagueB(Colleague* cb) {
		this->m_cb = cb;
	}
	void SendMsg(string msg,Colleague* c) {
		if( c == m_ca ) {
			m_ca->GetMsg(msg);
		}

		else if( c == m_cb ) {
			m_cb->GetMsg(msg);
		}
	}
private:
	Colleague* m_ca;
	Colleague* m_cb;
};


int main(int argc, char* argv[]) {
	ConcreteMediator* mediator = new ConcreteMediator();
	Colleague* ca = new ConcreteColleagueA(mediator);
	Colleague* cb = new ConcreteColleagueB(mediator);

	mediator->SetColleagueA(ca);
	mediator->SetColleagueB(cb);

	ca->SendMsg("Hello ");
	cb->SendMsg("World ");
}