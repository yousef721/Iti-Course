#include <iostream>
using namespace std;

class Base
{
protected: 
    int a;   // Shared variable (but without virtual → Derived would inherit TWO copies)
public:
    Base(): a(0) {};         
    Base(int a): a(a) {};     
    ~Base() {};               
};

class Base1 : virtual public Base   // virtual inheritance avoids duplicate Base
{
protected: 
    int b;  
public:
    Base1(): b(0) {};         
    Base1(int b): Base(b), b(b) {};  
    ~Base1() {};               
};

class Base2 : virtual public Base   // also virtual inheritance
{
protected:
    int c;  
public:
    Base2(): c(0) {};         
    Base2(int c): Base(c), c(c) {};
    ~Base2() {};               
};

class Derived : public Base1, public Base2
{
private:
    int d;  
public:
    // Because Base is virtual, Derived is responsible for initializing Base
    Derived(int x, int y, int z) : Base(x), Base1(y), Base2(z), d(z) {};

    int product() {
        // ✅ With virtual inheritance:
        // Only ONE copy of Base::a exists (no ambiguity)
        // Without virtual, this would cause an error: "ambiguous a"
        return a * b * c * d;  
    }
};

int main()
{
    Derived obj(2, 3, 4);

    // Values:
    // Base::a = 2
    // Base1::b = 3
    // Base2::c = 4
    // Derived::d = 4
    // Product = 2 * 3 * 4 * 4 = 96
    cout << "Product = " << obj.product() << endl; 
}
