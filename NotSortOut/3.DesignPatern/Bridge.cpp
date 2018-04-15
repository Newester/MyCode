#include <iostream>

using namespace std;

class Abstraction {
public:
	virtual ~Abstraction();
	virtual void Operation() = 0;
protected:
	Abstraction();
};

class AbstractionImp {
public:
	virtual ~AbstractionImp();
	virtual void Operation() = 0;
protected:
	AbstractionImp();
};

 class RefinedAbstraction : public Abstraction {
 public:
 	RefinedAbstraction(AbstractionImp* imp);
 	~RefinedAbstraction();
 	void Operation();
 private:
 	AbstractionImp* imp;
 };

class AbstractionImpA : public AbstractionImp {
public:
	 AbstractionImpA();
	~ AbstractionImpA();
	virtual void Operation();
};

class AbstractionImpB : public AbstractionImp {
public:
	AbstractionImpB();
	~AbstractionImpB();
	virtual void Operation();
};

int main(int argc, char* argv[]) {
	return 0;
}