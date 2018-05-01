/*
*
单例模式在实际开发过程中是很有用的，单例模式的特征总结：

1、一个类只有一个实例

2、提供一个全局访问点

3、禁止拷贝

逐个分析：

1、实现只有一个实例，需要做的事情：将构造函数声明为私有

2、提供一个全局访问点，需要做的事情：类中创建静态成员和静态成员方法

3、禁止拷贝：把拷贝构造函数声明为私有，并且不提供实现，将赋值运算符声明为私有，防止对象的赋值
*
*/
class Singleton
{
public:
    //get 方法
    static Singleton * getInstance(){
        if (nullptr == m_instance) {
            lock();
            //判断单例否
            if (nullptr == m_instance) {
                m_instance = new Singleton();
            }
            unlock();
        }
        //返回一个实例化的对象
        return m_instance;
    }
    //c++ 嵌套的内部类，作用是删除单例类对象，Garbage被定义为Singleton的私有内嵌类，以防该类被在其他地方滥用。
    class Garbage
    {
    public:
        ~Garbage(){
            if (nullptr != Singleton::instance) {
                cout << "单例类的唯一实例被析构了" << endl;
                delete Singleton::m_instance;
            }
        }
    };
    
private:
    //单例类中定义一个这样的静态成员变量，而它的唯一工作就是在析构函数中删除单例类的实例，利用程序在结束时析构全局变量的特性，选择最终的释放时机；
    static Garbage garbage;
    //声明一个静态的实例
    static Singleton *m_instance;
    //单例类的私有构造函数
    Singleton(){
        cout << "调用了单例类的构造函数" << endl;
    }
    //单例类的私有析构函数
    ~Singleton(){
        cout << "调用了单例类的析构函数" << endl;
    }
    //把拷贝构造函数声明为私有，就可以禁止外人拷贝对象，也不用实现它，声明私有即可
    Singleton(const Singleton &copy);
    //把赋值运算符重载为私有的，防止对象之间的赋值操作
    Singleton & operator=(const Singleton &other);
};
//初始化内部私有类的静态变量，目睹是启动删除的析构函数，如果不初始化，就不会被析构
//内部类可以访问外部类的私有成员，外部类不能访问内部类的私有成员！
Singleton::Garbage Singleton::garbage;
//初始化instance为 nullptr
Singleton * Singleton::m_instance = nullptr;

int main(int argc, char* argv[]) {
    Singleton *a = Singleton::getInstance();
    Singleton *b = Singleton::getInstance();
    Singleton *c = Singleton::getInstance();
    
    if (a == b) {
        cout << "a = b" << endl;
    }
    
    return 0;
}