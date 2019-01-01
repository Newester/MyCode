#include "Builder.h"

Product::Product() {
    ProducePart();
    cout << " constructor of class Product..." << endl;
}

Product::~Product() {
    cout << "destructor of class Product..." << endl;
}

void  Product::ProducePart() {
    cout << "build part of product..." << endl;
}

ProductPart::ProductPart() {
    cout << "constructor of class ProductPart..." << endl; 
}

ProductPart::~ProductPart() {
    cout << "destructor of class ProductPart..." << endl;
}

ProductPart* ProductPart::BuildPart() {
    return new ProductPart();
}

Builder::Builder() {
    cout << "constructor of class Builder..." << endl;
}

Builder::~Builder() {
    cout << "destructor of class Builder..." << endl;
}

ConcreteBuilder::ConcreteBuilder() {
    cout << "constructor of class ConcreteBuilder..." << endl;
}

ConcreteBuilder::~ConcreteBuilder() {
    cout << " destrcutor of class ConcreteBuilder..." << endl;
}

void ConcreteBuilder::BuildPartA(const string& param) {
    cout << "Step<1> Build Part A ... " << param << endl;
}

void ConcreteBuilder::BuildPartB(const string& param) {
    cout << "Step<2> Build Part B ... " << param << endl;
}

void ConcreteBuilder::BuildPartC(const string& param) {
    cout << "Step<3> Build Part C ... " << param << endl;
}

Product* ConcreteBuilder::GetProduct() {
    BuildPartA(string("pre-defined"));
    BuildPartB(string("pre-defined"));
    BuildPartC(string("pre-defined"));
    return new Product();
}

Director::Director(Builder* bld) {
    bld_ = bld;
}

Director::~Director() {

}

void Director::Construct() {
    bld_->BuildPartA("user-defined");
    bld_->BuildPartB("user-defined");
    bld_->BuildPartC("user-defined");
}