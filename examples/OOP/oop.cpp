#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base constructor \n"; }
    virtual void myPrint() { std::cout << "This is base \n"; }
    virtual void myPure() = 0;
    virtual ~Base() { std::cout << "Base deconstructor \n"; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived constructor \n"; }
    void myPrint() override { std::cout << "This is Derived \n"; }
    void myPure() override { std::cout << "This is pure Derived \n"; }
    ~Derived() override { std::cout << "Derived deconstructor \n"; }
};

int main()
{
    Base *base = new Derived();
    base->myPrint();
    base->myPure();
    delete base;
    return 0;
}
