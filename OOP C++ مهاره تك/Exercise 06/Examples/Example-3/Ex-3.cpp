#include <iostream>
using namespace std;

class Base
{
private:
    int a;         
protected:
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
    
    void publicMember()
    {
        cout << "In Base Class: "  << endl;
    }
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

    // Function Overriding 
    int product() { return Base::product() * c; }  // Call Product in Base class

    void PublicMember()
    {
        cout << "In Derived Class: "  << endl;
    }

    ~Derived(){};                         
};

void SomeFunctionB(Base t)
{
    t.publicMember();
}

void SomeFunctionD(Derived t)
{
    t.publicMember();
}


int main()
{
    Base bO(5,4);          // a=5, b=4
    Derived obj;           // a=0, b=0, c=0
    Derived obj2(10,20,30);// a=10, b=20, c=30

    Base *ptr = &obj2;     // Base pointer pointing to Derived object

    cout << "obj: " << bO.product() << endl;            // 5*4 = 20
    cout << "obj: " << obj.product() << endl;           // (0*0)*0 = 0 (Derived product)
    cout << "obj: " << obj.Base::product() << endl;     // (0*0) = 0 (Base product)

    cout << "obj2: " << obj2.product() << endl;         // (10*20)*30 = 6000 (Derived product)
    cout << "obj2: " << obj2.Base::product() << endl;   // (10*20) = 200 (Base product)
    cout << "obj2: " << ptr->product() << endl;         // (10*20) = 200 (Base product, no virtual)

    SomeFunctionB(bO);   // Prints: In Base Class
    SomeFunctionB(obj);  // Prints: In Base Class (object slicing, Derived ignored)

    // SomeFunctionD(bO); ❌ Error: Cannot convert Base to Derived
    SomeFunctionD(obj);  // Prints: In Base Class (same reason as above)
}

