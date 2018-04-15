#include <iostream>

using namespace std;

class AbstractProductA {
public:
	virtual ~AbstractProductA() { cout << "~AbstractProductA" << endl; }
protected:
	AbstractProductA() { cout << "AbstractProductA" << endl; }
private:
};

class AbstractProductB{
public:
	virtual ~AbstractProductB() { cout << "~AbstractProductB" << endl; }
protected:
	AbstractProductB() { cout << "AbstractProductB" << endl; }
private:
};

class ProductA1 : public AbstractProductA {
public:
	ProductA1() { cout << "ProductA1" << endl;}
	~ProductA1() { cout << "~ProductA1" << endl; }
protected:
private:
};

class ProductA2 : public AbstractProductA {
public:
	ProductA2() { cout << "ProductA2" << endl; }
	~ProductA2() { cout << "~ProductA2" << endl; }
protected:
private:
};

class ProductB1 : public AbstractProductB {
public:
	ProductB1() { cout << "ProductB1" << endl; }
	~ProductB1() { cout << "~ProductB1" << endl; }
protected:
private:
};

class ProductB2 : public AbstractProductB {
public:
	ProductB2() { cout << "ProductB2" << endl; }
	~ProductB2() { cout << "~ProductB2" << endl; }
protected:
private:
};

/************************/
class AbstractFactory {
public:
	virtual ~AbstractFactory() { cout<<"~AbstractFactory"<<endl; }
	virtual AbstractProductA * CreateProductA() = 0;
	virtual AbstractProductB * CreateProductB() = 0;
protected:
	AbstractFactory() { cout<<"AbstractFactory"<<endl; }
private:
};

class Factory1 : public AbstractFactory {
public:
	Factory1() { cout<<"Factory1"<<endl; }
	~Factory1() { cout<<"~Factory1"<<endl; }
	AbstractProductA * CreateProductA() { return new ProductA1(); }
	AbstractProductB * CreateProductB() { return new ProductB1(); }
protected:
private:
};

class Factory2 : public AbstractFactory {
public:
	Factory2() { cout<<"Factory2"<<endl; }
	~Factory2() { cout<<"~Factory2"<<endl; }
	AbstractProductA * CreateProductA() { return new ProductB1(); }
	AbstractProductB * CreateProductB() { return new ProductB2(); }
protected:
private:
};

int main(int argc, char* argv[]){
	AbstractFactory* fac1 = new Factory1();
	AbstractFactory* fac2 = new Factory2();

	pA1 = fac1->CreateProductA();
	pB1 = fac1->CreateProductB();

	delete pA1;
	delete pB1;
	delete fac1;

	pA2 = fac2->CreateProductA();
	pB2 = fac2->CreateProductB();

	delete pA2;
	delete pB2;
	delete fac2;

	return 0;
}

















