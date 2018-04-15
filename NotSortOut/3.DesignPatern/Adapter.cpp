#include <iostream>

using namespace std;

class Target
{
public:
	virtual ~Target();
    virtual void Request() { cout << "Target::Request" << endl; }
};

class Adaptee {
public:
	Adaptee();
	~Adaptee();
	void SpecificRequest() { cout << "Adaptee::SpecificRequest" << endl; }
};

class Adapter : public Target {
public:
	Adapter(Adaptee* adaptee) : adaptee(adaptee) {}
	~Adapter();
	void Request() { adaptee->SpecificRequest(); }
private:
	Adaptee* adaptee;
};

int main(int argc, char* argv[]) {
	Adaptee* adaptee = new Adaptee;
	Target* adapter = new Adapter(adaptee);//父类指针指向子类对象
	adapter->Request();
	delete adaptee;
	delete adapter;
	return 0;
}






























