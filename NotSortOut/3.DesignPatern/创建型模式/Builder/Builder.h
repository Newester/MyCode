#ifndef  __BUILDER_H__
#define _{_BUILDER_H__

#include <iostream>

using namespace std;

class Product {

public:
    Product();
    ~Product();
    void ProducePart();
protected:
private:
};

class ProductPart {

public:
    ProductPart();
    ~ProductPart();
    ProductPart* BuildPart();
protected:
private:
};

class Builder {

public:
    Builder();
    virtual ~Builder();
    virtual void BuildPartA(const string& param) = 0;
    virtual void BuildPartB(const string& param) = 0;
    virtual void BuildPartC(const string& param) = 0;
    virtual Product* GetProduct() = 0;
protected:
    Builder();
private:
};

class ConcreteBuilder : public Builder {

public:
    ConcreteBuilder();
    ~ConcreteBuilder();
    void BuildPartA(const string& param);
    void BuildPartB(const string& param);
    void BuildPartC(const string& param);
    Product* GetProduct();
protected:
private:
};

class Director {

public:
    Director(Builder* bld);
    ~Director();
    void Construct();
protected:
private:
    Builder* bld_;
};

#endif // __BUILDER_H__