#include <iostream>


// Multi-Level Inheritance Base -> Derived -> SecondDerived
using namespace std;
class Base
{
private:
    int a;
    int b;
public:
    Base(): a(0), b(0){};
    Base(int n): a(n), b(n){};
    Base(int x, int y): a(x), b(y){};
    
    void setA (int x) { a = x; }
    void setB (int y) { b = y; }

    int getA() { return a; }
    int getB() { return b; }

    int product() { return a * b; }
    ~Base(){};
};

class Derived : public Base
{
private:
    int c;
public:
    Derived() : Base(), c(0) {};
    Derived(int n): Base(n), c(n) {};
    Derived(int x, int y, int z): Base(x, y), c(z) {};
    
    void setC (int z) { c = z; }

    int getc() { return c; }

    int product() { return Base::product() * c; }
    ~Derived(){};
};

class SecondDerived : public Derived
{
private:
    int d;
public:
    SecondDerived() : Derived(), d(0) {};
    SecondDerived(int n): Derived(n), d(n) {};
    SecondDerived(int x, int y, int z, int d): Derived(x, y, z), d(d) {};
    
    void setD(int z) { d = z; }

    int getD() { return d; }

    int product() { return Derived::product() * d; }
    ~SecondDerived(){};
};

int main()
{
}