/*
 *@brief 外观模式
 *@details通过外观的包装，使应用程序只能看到外观对象，而不会看到具体的细节对象，这样无疑会降低应用程序的复杂度，并且提高了程序的可维护性
 *@details 为子系统中的一组接口提供一个一致的界面， Facade模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。引入外观角色之后，用户只需要直接与外观角色交互，用户与子系统之间的复杂关系由外观角色来实现，从而降低了系统的耦合度。
 *@details     1) 当你要为一个复杂子系统提供一个简单接口时。子系统往往因为不断演化而变得越来越复杂。大多数模式使用时都会产生更多更小的类。
    这使得子系统更具可重用性，也更容易对子系统进行定制，但这也给那些不需要定制子系统的用户带来一些使用上的困难。facade可以提供一个简单的缺省视图，
    这一视图对大多数用户来说已经足够，而那些需要更多的可定制性的用户可以越过facade层。
    2) 客户程序与抽象类的实现部分之间存在着很大的依赖性。引入 facade将这个子系统与客户以及其他的子系统分离，可以提高子系统的独立性 和可移植性。
    3) 当你需要构建一个层次结构的子系统时，使用 facade模式定义子系统中每层的入口点。如果子系统之间是相互依赖的，你可以让它们仅通过facade进行通讯，从而简化了它们之间的依赖关系。
    @details 1）对客户屏蔽子系统组件，减少了客户处理的对象数目并使得子系统使用起来更加容易。通过引入外观模式，客户代码将变得很简单，与之关联的对象也很少。
2）实现了子系统与客户之间的松耦合关系，这使得子系统的组件变化不会影响到调用它的客户类，只需要调整外观类即可。
3）降低了大型软件系统中的编译依赖性，并简化了系统在不同平台之间的移植过程，因为编译一个子系统一般不需要编译所有其他的子系统。一个子系统的修改对其他子系统没有任何影响，而且子系统内部变化也不会影响到外观对象。
4）只是提供了一个访问子系统的统一入口，并不影响用户直接使用子系统类。
Facade模式的缺点
1） 不能很好地限制客户使用子系统类，如果对客户访问子系统类做太多的限制则减少了可变性和灵活性。
2） 在不引入抽象外观类的情况下，增加新的子系统可能需要修改外观类或客户端的源代码，违背了“开闭原则”。

*/

#include <iostream>

using namespace std;

class SubsystemA {
public:
	SubsystemA() {}
	~SubsystemA() {}
	void Operation() {
		cout << "SubsystemA::Operation... " << endl;
	}

};

class SubsystemB {
public:
	SubsystemB() {}
	~SubsystemB() {}
	void Operation() {
		cout << "SubsystemB::Operation... " << endl;
	}
};

class Facade {
public:
	Facade() {
		this->m_subSysA = new SubsystemA();
		this->m_subSysB = new SubsystemB();
	}
	~Facade() {
		delete this->m_subSysA;
		delete this->m_subSysB;

		this->m_subSysA = nullptr;
		this->m_subSysB = nullptr;
	}
	void OperationWrapper() {
		this->m_subSysA->Operation();
		this->m_subSysB->Operation();
	}
private:
	SubsystemA* m_subSysA;
	SubsystemB* m_subSysB;
};
