/**
 *@brief 备忘录模式
 *@details 在不破坏封装性的前提下，捕获一个对象的状态，并在该对象之外保存这个状态，这样以后就可以将该对象恢复到原先保存的状态
**/

#include <iostream>
#include <string>

using namespace std;

class Originator;

//Memento
class Memento {
private:
	friend class Originator;
	Memento(const string& state) {
		this->m_state = state;
	}
	~Memento() {}
	void SetState(const string& state) {
		this->m_state = state;
	}
	string GetState() {
		return this->m_state;
	}
	string m_state;
};

//创建和使用Memento
class Originator {
public:
	Originator() {}
	Originator(const string& state) {
		return this->m_state;
	}
	~Originator() {}
	void RestoreToMemento(Memento* memento) {
		this->m_state = memento->GetState();
	}
	Memento* CreateMemento() {
		return new Memento(this->m_state);
	}
	void SetState(const string& state) {
		this->m_state = state;
	}
	string GetState() {
		return this->m_state;
	}
	void show() {
		cout << this->m_state << endl;
	}
private:
	string m_state;
};

//保存Memento
class CareTaker {
public:
	CareTaker() {}
	~CareTaker() {}
	void SetMemento(Memento* memento) {
		this->m_memento = memento;
	}
	Memento* GetMemento() {
		return this->m_memento;
	}
private:
	Memento* m_memento;

};

int main(int argc, char* argv[]) {
	Originator* o = new Originator("old");
	o->show();

	CareTaker* caretaker = new CareTaker();
	CareTaker->SetMemento(o->CreateMemento());

	o->SetState("New");
	o->show();

	o->RestoreToMemento(caretaker->GetMemento());
	o->show();

	return 0;
}