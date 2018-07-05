/**
 *@brief 命令模式
 *@details 将一个请求封装为一个对象，从而用不同的请求对客户进行参数化
 *	对请求排队或记录请求日志，以及支持可撤销的操作
 *	
 *	优点：可以很容易地设计一个命令队列
 *		 可以容易地将命令记入日志
 *		 允许接收请求的一方决定是否要否决请求
 *		 可以很容易实现对请求的撤销和重做
 *		 增加新的具体命令类很容易
 *
 */

#include <iostream>

using namespace std;

class Command {
public:
	virtual ~Command(){}
	virtual void Execute() = 0;
protected:
	Command(){}
	
};

class Reciever {
public:
	Reciever() {}
	~Reciever() {}
	void Action() {
		cout << "Reciever::Action()... " << endl;
	}

};

class ConcreteCommand : public Command {
public:
	ConcreteCommand(Receiver* rcv) {
		this->m_rcv = rcv;
	}
	~ConcreteCommand() {}
	virtual void Execute() {
		this->m_rcv->Action();
	}
private:
	Receiver* m_rcv;

};

class Invoker {
public:
	Invoker(Command* cmd) {
		this->m_cmd = cmd;
	}
	~Invoker() {}
	void Invoke() {
		this->m_cmd->Execute();
	}
private:
	Command* m_cmd;

};

int main(int argc, char const *argv[]) {
	Reciever* rcv = new Reciever();
	Command* cmd = new ConcreteCommand(rcv);
	Invoker*  inv = new Invoker(cmd);
	inv->Invoke();
	return 0;
}

