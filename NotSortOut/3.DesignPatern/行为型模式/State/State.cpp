/**
 *@brief 状态模式
**/

#include <iostream>

using namespace std;

class Context;
class State {
public:
	virtual void Handle(Context* context) = 0;
	~State() {}
protected:
	State() {}
	
};

class ConcreteStateA : public State {
public:
	ConcreteStateA() {}
	~ConcreteStateA() {}
	virtual void Handle(Context* context) {
		cout << "ConcreteStateA::Handle()... " << endl;
		context->ChangeState(new ConcreteStateB());
	}
};

class ConcreteStateB : piblic State {
public:
	ConcreteStateB() {}
	~ConcreteStateB() {}
	virtual void Handle(Context* context) {
		cout << "ConcreteStateB::Handle()... " <<  endl;
		context->ChangeState(new ConcreteStateA());
	}
};

class Context {
public:
	Context(State* state) {
		this->m_state = state;
	}
	~Context() {}
	void Request() {
		if( nullptr != this->m_state ) {
			this->m_state->Handle(this);
		}
	}
	void ChangeState(State* state) {
		this->m_state = state;
	}
private:
	State* m_state;
};

int main(int argc, char const *argv[])
{
	State* state = new ConcreteStateA();
	Context* context = new Context(state);

	context->Request();
	context->Request();
	context->Request();
	return 0;
}