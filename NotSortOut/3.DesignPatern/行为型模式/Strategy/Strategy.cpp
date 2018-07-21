/**
 *@brief 策略模式
**/

class Strategy {
public:
    ~Strategy() {}
    virtual void AlgrithmInterface = 0;
protected:
	Strategy() {}

};

class ConcreteStragetyA : public Strategy {
public:
	ConcreteStragetyA() {}
	~ConcreteStragetyA() {}
	void AlgrithmInterface() {
		cout << "ConcreteStragetyA::AlgrithmInterface()... " << endl;
	}
};

class ConcreteStrategyB : public Strategy {
public:
	ConcreteStrategyB() {}
	~ConcreteStrategyB() {}
	void AlgrithmInterface() {
		cout << "ConcreteStrategyB::AlgrithmInterface()... " << endl;
	}
	
};

class Context
{
public:
	Context(Strategy* strategy) {
		this->m_strategy = strategy;
	}
	~Context() {
		delete this->m_strategy;
	}
	void DoAction() {
		this->m_strategy->AlgrithmInterface();
	}
private:
	Strategy* m_strategy;
	
};

int main(int argc, char const *argv[]) {
	Strategy* strategy = new ConcreteStragetyA();
	Context* context = new Context(strategy);
	return 0;
}