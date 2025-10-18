#include <iostream>

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

    int productAB() { return a * b; }
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

    int productABC() { return productAB() * c; }
    ~Derived(){};
};

int main()
{
    Derived obj1;

    obj1.setA(3);
    obj1.setB(7);
    obj1.setC(1);


    cout << "obj1: " << obj1.productAB() << endl;
    cout << "obj1: " << obj1.productABC() << endl;

    Base obj2;

    obj2.setA(3);
    obj2.setB(7);
    // obj2.setC(1); // error Base class not contain method getC();


    cout << "obj2: " << obj2.productAB() << endl;
    // cout << "obj2: " << obj2.productABC() << endl; // error 
}