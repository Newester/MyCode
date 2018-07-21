/**
 *@brief 访问者模式
**/

#include <iostream>
#include <vector>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
	virtual void VisitConcreteElementA(ConcreteElementA* elementA) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB* elementB) = 0;
};

class ConcreteVisitorA : public Visitor {
public:
	void VisitConcreteElementA(ConcreteElementA* elementA) {}
	void VisitConcreteElementB(ConcreteElementB* elementB) {}
}; 

class ConcreteVisitorB : public Visitor {
public:
	void VisitConcreteElementA(ConcreteElementA* elementA) {}
	void VisitConcreteElementB(ConcreteElementB* elementB) {}
};

class Element {
public:
	virtual void Accept(Visitor* visitor) = 0;
};

class ConcreteElementA : public Element {
public:
	void Accept(Visitor* visitor) {
		visitor->VisitConcreteElementA(this);
	}
};

class ConcreteElementB : public Element {
	void Accept(Visitor* visitor) {
		visitor->VisitConcreteElementB(this);
	}
};

class ObjectStructure {
public:
	void Attach(Element* element) {
		m_elements.push_back(element);
	}
	void Dettach(Element* element) {
		vector<Element*>::iterator it = find(m_elements.begin(),m_element.end(),element);
		if( it != m_elements.end() ) {
			m_elements.erase(it);
		}
	}
	void Accept(Visitor* visitor) {
		vector<Element*>::iterator it = m_elements.begin();
		for(;it != m_elements.end();++it) {
			(*it)->Accept(visitor);
		}
	}
private:
	vector<Element*> m_elements;
};

int main(int argc, char* argv[]) {
	
	ObjectStructure* obj = new ObjectStructure;

	ConcreteElementA* ea = new ConcreteElementA;
	ConcreteElementB* eb = new ConcreteElementB;

	ConcreteVisitorA* va = new ConcreteVisitorA;
	ConcreteVisitorB* vb = new ConcreteVisitorB;

	obj->Accept(va);
	obj->Accept(vb);
	
	return 0;

}