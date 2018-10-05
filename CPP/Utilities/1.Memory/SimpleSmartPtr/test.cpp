#include <iostream>
#include "SmartPtr.hpp"

using namespace std;
class Test {
public:
    explicit Test() {
        
    }
    ~Test() {
        std::cout << "Test Delete ..." << std::endl;
    }
    static Test* GetInstance() {
        if(m_instance.IsEmpty()) {
            m_instance.LoadIn(new Test());
        }
        return m_instance.Get();
    }
private:
    static SmartPtr<Test> m_instance;
};

SmartPtr<Test> Test::m_instance(nullptr);

int main(int argc, char* argv[]) {
    Test* t = Test::GetInstance();
    return 0;
}