/**
 *@brief Interpreter模式
 *@details Interpreter模式提供了一个实现语法解释器的框架，其目的就是使用一个解释器为用户提供一个一门定义语言语法表示的解释器，并且通过这个解释器来解释语言中的句子。
 *@details Interpreter模式使用类来表示文法规则，因此方便于文法的扩展。
 *
**/



#include <iostream>
#include <string>

using namespace std;

class Context {
public:
	Context() {}
	~Context() {}
};

class AbstractExpression {
public:
	virtual ~AbstractExpression() {}
	virtual void Interpret(const Context& c) {}
protected:
	AbstractExpression() {}
};

class TerminalExpresion: public AbstractExpression {
public:
	TerminalExpresion(const string& statement) {
		m_statement = statement;
	}
	~TerminalExpresion() {}
	void Interpret(const Context& c) {
		cout << "TerminalExpresion::Interpret()... " << endl;
	}
private:
	string m_statement;
};

class NonterminalExpression : public AbstractExpression {
public:
	NonterminalExpression(AbstractExpression* ex, int times) {
		m_ex = ex;
		m_times = times;
	}
	~NonterminalExpression() {}
	void Interpret(const Context& c) {
		for(int i = 0; i < m_times; ++i) {
			m_ex->Interpret(c);	
		}
	}
private:
	AbstractExpression* m_ex;
	int m_times;
};

void int main(int argc, char* argv[]) {
	Context* c = new Context();
	AbstractExpression* abex = new TerminalExpresion("Hello");
	AbstractExpression* nabex = new NonterminalExpression(abex,2);
	nabex->Interpret(*c);

	delete nabex;
	delete abs;
	delete c;

}