/*Flyweight享元模式

作用：运用共享技术有效地支持大量细粒度的对象。

内部状态intrinsic和外部状态extrinsic：

1）Flyweight模式中，最重要的是将对象分解成intrinsic和extrinsic两部分。

2）内部状态：在享元对象内部并且不会随环境改变而改变的共享部分，可以称为是享元对象的内部状态

3）外部状态：而随环境改变而改变的，取决于应用环境，或是实时数据，这些不可以共享的东西就是外部状态了。

4）内部状态和外部状态之间的区别：
　　在Flyweight模式应用中，通常修改的是外部状态属性，而内部状态属性一般都是用于参考或计算时引用。
Flyweight执行时所需的状态必定是内部的或外部的。内部状态存储于ConcreteFlyweight对象之中；而外部状态则由Client对象存储或计算。当用户调用Flyweight对象的操作时，将该状态传递给它。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flyweight {
public:
	virtual void Operation(const string& extrinsicState) = 0;
	string GetInstrinsicState() {
		return this->m_intrinsicState;
	}
	virtual ~Flyweight() {}
protected:
	Flyweight(string instrinsicState) {
		this->m_intrinsicState = instrinsicState;
	}
private:
	string m_intrinsicState;
};

class ConcreteFlyweight : public Flyweight {
public:
	virtual void Operation(const string& extrinsicState) {
		cout << this->GetInstrinsicState() << endl;
		cout << extrinsicState << endl;
	}
	ConcreteFlyweight(string instrinsicState) : Flyweight(instrinsicState) {}
	~ConcreteFlyweight() {}
};

class UnsharedConcreteFlyweight : public Flyweight {
public:
	virtual void Operation(const string& extrinsicState) {
		cout << extrinsicState << endl;
	}
	UnsharedConcreteFlyweight(string instrinsicState) : Flyweight(instrinsicState) {}
	~UnsharedConcreteFlyweight() {}
};

class FlyweightFactory {
public:
	FlyweightFactory() {}
	~FlyweightFactory() {}
	Flyweight* GetFlyweight(string key) {
		vector<Flyweight*>::iterator it = this->m_vecFly.begin();
		for(;it != this->m_vecFly.end(); it++) {
			if( key == (*it)->GetInstrinsicState() ) {
				return *it;
			}
		}
		Flyweight* fly = new ConcreteFlyweight(key);
		this->m_vecFly.push_back(fly);
		return fly;
	}
	void GetFlyweightCount() {
		cout << this->m_vecFly.size() << endl;
	}
protected:
private:
	vector<Flyweight*> m_vecFly;
};

int main(int argc, char* argv[]) {

	string extrinsicState = "ext";

	FlyweightFactory* fc = new FlyweightFactory();

	Flyweight* fly = fc->GetFlyweight("ins");

	fly->Operation(extrinsicState);

	fc->GetFlyweightCount();

	return 0;
}