/**
 *@brief 责任链模式
 *@details 将请求的接收者连成一条链，沿着这条链传递请求,直到有对象处理它
**/

#include <iostream>

class Handle {
public:
	virtual ~Handle() {
		if( nullptr != m_successor) {
			delete m_successor;
			m_successor = nullptr;			
		}

	}
	virtual void HandleRequest() = 0;
	void SetSuccessor(Handle* succ) {
		this->m_successor = succ;
	}
	Handle* GetSuccessor() {
		return this->m_successor;
	}
protected:
	Handle() {
		m_successor = nullptr;
	}
	Handle(Handle* succ) {
		m_successor = succ;
	}
private:
	m_successor;
};

class ConcreteHandleA : public Handle
{
public:
	ConcreteHandleA() {}
	~ConcreteHandleA() {}
	ConcreteHandleA(Handle* succ) : Handle(succ) {}
	void HandleRequest() {
		if( nullptr != this->GetSuccessor() ) {
			cout << "ConcreteHandleA把处理权交给后继结点... " << endl;
			this->GetSuccessor()->HandleRequest();
		}
		else
		{
			cout << "ConcreteHandleA没有后继了，正在自行处理。。。"
		}
	}
	
};

class ConcreteHandleB : public Handle
{
public:
	ConcreteHandleB() {}
	~ConcreteHandleB() {}
	ConcreteHandleB(Handle* succ) : Handle(succ) {}
	void HandleRequest() {
		if( nullptr != this->GetSuccessor() ) {
			cout << "ConcreteHandleB交由后续结点处理... " << endl;	
		 	this->GetSuccessor()->HandleRequest();
		} else {
			cout << "ConcreteHandleA没有后续节点了，正在自行处理... " << endl;
		}
	}
	
};


int main(int argc, char* argv[]) {
	Handle* ha = new ConcreteHandleA();
	Handle* hb = new ConcreteHandleB();
	ha->SetSuccessor(hb);
	ha->HandleRequest();
	return 0;
}