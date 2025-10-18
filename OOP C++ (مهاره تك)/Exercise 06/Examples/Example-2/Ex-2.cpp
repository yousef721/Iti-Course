#include <iostream>
using namespace std;

class Base
{
private:
    int a;          // private: accessible only inside Base
protected:
    int b;          // protected: accessible inside Base and Derived
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
    int c;                                    // private: only Derived can access it
public:
    Derived() : Base(), c(0) {};              
    Derived(int n): Base(n), c(n) {};         
    Derived(int x, int y, int z): Base(x, y), c(z) {}; 
    
    void setC (int z) { c = z; }              
    int getc() { return c; }                 

    // productABC uses:
    // getA() -> allowed (public)
    // b -> allowed (protected, accessible in Derived)
    // c -> allowed (private in Derived)
    int productABC() { return getA() * b * c; }  
    ~Derived(){};                         
};

int main()
{
    Base bO;
    Derived obj1;

    // bO.a; ❌ error: a is private in Base
    // bO.b; ❌ error: b is protected in Base
    // obj1.b; ❌ error: b is protected, not accessible by object
}
