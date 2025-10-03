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

class Derived : public Base 
{
public:
    Derived() : Base() {};
    void dosomething()
    {
        a = 10; // ✅ Allowed (public in Base, still public in Derived)
        b = 20; // ✅ Allowed (protected in Base, accessible inside Derived)
        // c = 30; ❌ ERROR → (private in Base, not visible to Derived)
    }
    ~Derived(){};
};


int main()
{
    Derived obj;

    obj.a = 10; // ✅ Allowed (public in Base → public in Derived)
    // obj.b = 20; ❌ Not Allowed, Compiler error -> protected: not accessible outside
    // obj.c = 30; ❌ Not Allowed, Compiler error -> private: never accessible outside Base
}
