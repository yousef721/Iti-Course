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

class Derived : private Base // Private Inheritance
{
public:
    void dosomething()
    {
        a = 10; // ✅ Allowed → but 'a' becomes PRIVATE here
        b = 20; // ✅ Allowed → but 'b' becomes PRIVATE here
        // c = 30; ❌ ERROR → 'c' is private in Base
    }
};


class Derived2 : public Derived
{
public:
    void dosomething()
    {
        // a = 10; // ❌ ERROR → 'a' became private in Derived, not accessible in Derived2
        // b = 20; // ❌ ERROR → 'b' also became private in Derived
        // c = 30; ❌ ERROR → c still private in Base
    }
};


int main()
{
    Derived obj;

    // obj.a = 10; // ❌ Not Allowed, Compiler error -> a private in Derived
    // obj.b = 20; // ❌ Not Allowed, Compiler error -> b private in Derived
    // obj.c = 30; // ❌ Not Allowed, Compiler error -> c private in Base 
}