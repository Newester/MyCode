/*
 *Subject（抽象主题）：声明了 RealSubject 与 Proxy 的共同接口，定义了某个/些功能。
 *RealSubject（真实主题）：通常执行具体的业务逻辑，Proxy 控制对它的访问。
 *Proxy（代理）：持有一个 RealSubject 引用（指针），可以在需要时将请求转发给 RealSubject，以此起到代理的作用。
 *Client（客户端）：通过 Proxy 间接地与 RealSubject 进行交互
 *Proxy 和 RealSubject 都实现了 Subject 的接口，这允许 Client 可以像处理 RealSubject 一样处理 Proxy
 *远程代理（Remote Proxy） 
  为一个位于不同地址空间的对象提供一个本地代理，对代理的方法调用会导致对远程对象的方法调用。ATM 就是一个例子，ATM 可能会持有（存在于远程服务器中的）银行信息的一个代理对象。

 *虚拟代理（Virtual Proxy） 
  使用虚拟代理，代理可以作为一个（资源消耗较大的）对象的代表。虚拟代理经常延迟对象的创建，直到需要为止。在创建对象之前（及创建对象过程中），虚拟代理也可以作为对象的代理；之后，代理将请求直接委托给 RealSubject。

 *保护代理（Protection Proxy） 
  根据访问权限，可以使用保护代理来控制对资源的访问。例如，有一个员工对象，保护代理可以允许普通员工调用对象的某些方法，管理员调用其他方法。

 *缓冲代理（Cache Proxy） 
  为某一个目标操作的结果提供临时的存储空间，以便多个客户端可以共享这些结果。

 *智能引用代理（Smart Reference Proxy） 
  当一个对象被引用时，提供一些额外的操作（例如：将对象被调用的次数记录下来）。
*/

#include <iostream>

using namespace std;

class Subject {
public:
	virtual ~Subject() {}
	virtual void Request() = 0;
protected:
	Subject() {}
};

class ConcreteSubject : public Subject {
public:
	ConcreteSubject() {}
	~ConcreteSubject() {}
	virtual void Request() {
		cout << "ConcreteSubject::Request... " << endl;
	}
};

class Proxy : public Subject {
public:
	Proxy() : m_subject(nullptr) {}
	~Proxy() {}
	void DoSomething() {
		cout << "Proxy::DoSomething... " << endl;
	}
	void DoSomethingElse() {
		cout << "Proxy::DoSomethingElse... " << endl;
	}
	virtual void Request() {
		if(nullptr == this->m_subject) {
			this->m_subject = new ConcreteSubject();
		}

		this->DoSomething();
		this->m_subject->Request();
		this->DoSomethingElse();
	}
private:
	Subject* m_subject;
};

int main(int argc, char* argv[]) {
	Proxy* proxy = new Proxy();
	proxy->Request();
}