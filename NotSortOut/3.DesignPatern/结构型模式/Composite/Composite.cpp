/*
 *@brief 组合模式，将对象组合成树形结构表现“总体/部分”层次结构
 *＠details 使用组合结构可以将同样的操作应用在组合和个别对象上
 *@details 在大多数情况下，忽略组合和个别对象的差别
*/

#include <isotream>
#include <vector>

using namespace std;

/*
 *@brief Component基类，为组合中的对象声明接口
*/
class Component {
public:
	virtual void Operation() = 0;
	virtual void Add(Component* com) {
		cout << "Add SubComponent... " << endl;
	}
	virtual void Remove(Component* com) {
		cout << "Remove SubComponent... " << endl;
	}
	virtual Component* GetChild(int index) {
		return nullptr;
	}
	virtual ~Component() {}
protected:
	Component() {}

};
void Component::Operation() {}


/*
 *@brief 叶子节点，不包含任何子组件,只需实现操作接口
*/
class Leaf : public Component {
public:
	virtual void Operation() {
		cout << "Leaf::Operation()... " << endl;
	}
	Leaf() {}
	~Leaf() {}

};

/*
 *@brief 含子组件的类，需要实现所有接口
*/
class Composite : public Component {
public:
	Composite() {}
	~Composite() {}
	void Operation() {
		cout << "Composite::Operation()... " << endl;
		vector<Component*> ::iterator it = m_SubComVec.begin();
		for(; it != m_SubComVec.end(); it++) {
			(*it)->Operation();
		}
	}
	void Add(Component* com) {
		m_SubComVec.push_back(com);
	}
	void Remove(Component* com) {
		m_SubComVec.erase(&com);
	}
	Component* GetChild(int index) {
		if(index < 0 || index > m_SubComVec.size()) {
			return nullptr;
		}
		return m_SubComVec[index];
	}
private:
	//本例使用vector保存子组件
	vector<Component*> m_SubComVec;

};

int main(int argc, char* argv[]) {
	Composite* root = new Composite();
	root->Add(new Leaf());
	root->Operation();
	root->GetChild(0)->Operation();

}