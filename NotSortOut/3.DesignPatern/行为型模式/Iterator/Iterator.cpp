/**
 *@brief 迭代器模式
 *@details 提供一种方法顺序访问一个聚合对象中各个元素，而又不暴露该对象的内部表示。
 *@details 当你需要访问一个聚集对象，而且不管这些对象是什么都需要遍 历的时候，就应该考虑用迭代器模式。同时需要对聚集有多种方式遍历时，可以考虑用迭代器模式。
 *@details 为遍历不同的聚集结构提供如开始、下一个、是否结束、当前哪 一项等统一接口。
 *@details 迭代器模式就是分离了集合对象的遍历行为，抽象出一个迭代器类来负责，这样既可以做到不暴露集合的内部结构，又可让外部代码透明地访问集 合内部的数据。
 */

#include <iostram>
#include <string>
#include <vector>

using namespace std;

//迭代抽象类
class Iterator {
public:
	Iterator() {}
	~Iterator() {}
	virtual string First() = 0;
	virtual string Next() = 0;
	virtual string GetCur() = 0;
	virtual bool IsEnd() = 0;

};

//聚集抽象类
class Aggregate {
public:
	virtual int Count() = 0;
	virtual void Push(const string& strValue) = 0;
	virtual string Pop(const int index) = 0;
	virtual Iterator* CreateIterator() = 0;
};

class ConcreteIterator : public Iterator {
public:
	ConcreteIterator(Aggregate* aggregate) : m_indexCurrent(0),Iterator() {
		m_aggregate = aggregate;
	}
	string First() {
		return m_aggregate->Pop(0);
	}
	string Next() {
		string ret;
		m_indexCurrent++;
		if(m_indexCurrent < m_aggregate->Count()) {
			ret = m_aggregate->Pop(m_indexCurrent);
		}
		re!turn ret;
	}
	string GetCur() {
		return m_aggregate->Pop(m_indexCurrent);
	}

	bool IsEnd() {
		return (m_indexCurrent > m_aggregate->Count())?true:false;
	}
private:
	Aggregate* m_aggregate;
	int m_indexCurrent;
};

class ConcreteAggregate : public Aggregate {
public:
	ConcreteAggregate() : m_iterator(nullptr) {
		m_itemVec.clear();
	}
	~ConcreteAggregate() {
		if(nullptr == m_iterator) {
			delete m_iterator;
			m_iterator = nullptr;
		}
	}
	Iterator* CreateIterator() {
		if(nullptr == m_iterator) {
			m_iterator = new ConcreteIterator(this);
		}
		return m_iterator;
	}
	int Count() {
		return m_itemVec.size();
	}
	void Push(const string& value) {
		m_itemVec.push(value);
	}
	string Pop(const int index) {
		string ret;
		if(index < Count()) {
			ret = m_itemVec[index];
		}
		return  ret;
	}
private:
	vector<string> m_itemVec;
	Iterator* m_iterator;
};

int main(int argc, char* argv[]) {
	Aggregate* ca = new ConcreteAggregate();
	ca->Push("Hello");
	ca->Push("World");
	Iterator* it = ca->CreateIterator();
	string item = it->First();
	while(false == it->IsEnd()) {
		cout << it->GetCur << endl;
		it->Next();
	}
	return 0;
}