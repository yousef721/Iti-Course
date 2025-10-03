#include <iostream>
using namespace std;

// First Base Class
class Base1
{
protected: 
    int a;   // Protected → accessible in Base1 and Derived
public:
    Base1(): a(0) {};         
    Base1(int b): a(b) {};     
    ~Base1() {};               
};

// Second Base Class
class Base2
{
protected:
    int b;   // Protected → accessible in Base2 and Derived
public:
    Base2(): b(0) {};         
    Base2(int b): b(b) {};     
    ~Base2() {};               
};

// Derived inherits from BOTH Base1 and Base2
class Derived : public Base1, public Base2
{
private:
    int c;  // Private to Derived
public:
    // Constructor → calls Base1(x), Base2(y), and initializes c
    Derived(int x, int y, int z) : Base1(x), Base2(y), c(z) {};

    // Method → multiply all three values together
    int product() { return a * b * c; }

    ~Derived() {};
};

int main()
{
    // Create Derived object with values for a, b, c
    Derived obj(2, 3, 4);

    cout << "Product = " << obj.product() << endl; // 2 * 3 * 4 = 24
}
