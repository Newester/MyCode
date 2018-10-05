/*
 *@brief 简易的智能指针模板，
 * @details 栈上对象管理堆上内存，通过一个静态成员保存对象的指针，使其在析构时能调用对象的析构函数，释放堆内存
 * 
*/
#include <iostream>

template <class T>
class SmartPtr {
public:
    explicit SmartPtr(T* object = nullptr);
    ~SmartPtr();
    bool LoadIn(T* object);
    void UnLoad(void);
    T* Get(void);
    void ReSet(T* object);
    bool IsEmpty(void);
private:
    T* m_ptr;
};

template <class T>
SmartPtr<T>::SmartPtr(T* object) {
    m_ptr =  object;
}

template <class T>
SmartPtr<T>::~SmartPtr() {
    if( m_ptr != nullptr) {
        delete m_ptr;
    }
}

template <class T>
bool  SmartPtr<T>::LoadIn(T* object) {
    if( m_ptr == nullptr) {
        m_ptr = object;
        return true;
    }
    else {
        return false;
    }
}

template <class T>
void SmartPtr<T>::UnLoad() {
    m_ptr = nullptr;
}
template <class T>
T* SmartPtr<T>::Get() {
    return m_ptr;
}

template <class T>
void SmartPtr<T>::ReSet(T* object) {
    m_ptr = object;
}

template <class T>
bool SmartPtr<T>::IsEmpty() {
    if(m_ptr == nullptr) {
        return true;
    }
    return false;
}