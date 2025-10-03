#include <iostream>

using namespace std;
class Base
{
public:
    int a;        // public → accessible anywhere
protected:
    int b;        // protected → accessible in Base + Derived, but not outside
private:
    int c;        // private → accessible only inside Base
public:
    Base(): a(0), b(0){}; 
    ~Base(){};
};

class Derived : protected Base // Protected Inheritance
{
public:
    void dosomething()
    {
        a = 10; // ✅ Allowed → but 'a' becomes PROTECTED here
        b = 20; // ✅ Allowed → still protected
        // c = 30; ❌ ERROR → 'c' is private in Base
    }
};


class Derived2 : public Derived
{
public:
    void dosomething()
    {
        a = 10; // ✅ Allowed → 'a' is protected in Derived, so still accessible here
        b = 20; // ✅ Allowed → 'b' was always protected
        // c = 30; ❌ ERROR → still private in Base
    }
};


int main()
{
    Derived obj;

    // obj.a = 10; // ❌ Not Allowed, Compiler error -> a protected in Derived
    // obj.b = 20; // ❌ Not Allowed, Compiler error -> b protected in Derived
    // obj.c = 30; // ❌ Not Allowed, Compiler error -> c private in Base 
}