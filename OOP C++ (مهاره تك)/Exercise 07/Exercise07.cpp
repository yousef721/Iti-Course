#include <iostream>
using namespace std;

// ========================
// Base Class
// ========================
class GeoShape
{
protected:
    float dim1, dim2;  
public:
    GeoShape() : dim1(0), dim2(0) {}; 
    GeoShape(float dim) : dim1(dim), dim2(dim) {}; 
    GeoShape(float d1, float d2) : dim1(d1), dim2(d2) {}; 

    void setDim1(float d){ dim1 = d; }
    void setDim2(float d){ dim2 = d; }
    float getDim1(){ return dim1; }
    float getDim2(){ return dim2; }

    virtual float calculateArea(){ return 0; }
    ~GeoShape(){}
};

// ========================
// Triangle (Public Inheritance)
// ========================
class Triangle : public GeoShape
{
public:
    Triangle(float b, float h) : GeoShape(b, h) {}
    float calculateArea(){ return 0.5 * dim1 * dim2; }
};

// ========================
// Rectangle (Public Inheritance)
// ========================
class Rectangle : public GeoShape
{
public:
    Rectangle(float x, float y) : GeoShape(x, y) {}
    float calculateArea(){ return dim1 * dim2; }
};

// ========================
// Circle - Version 1: Public Inheritance (❌ can be violated)
// ========================
class Circle_Public : public GeoShape
{
public:
    Circle_Public(float r) : GeoShape(r,r) {}

    float calculateArea(){ return 22.0/7 * dim1 * dim2; }
};

// ========================
// Square - Version 1: Public Inheritance (❌ can be violated)
// ========================
class Square_Public : public Rectangle
{
public:
    Square_Public(float r) : Rectangle(r,r) {}
    float calculateArea(){ return Rectangle::calculateArea(); }
};

// ========================
// Circle - Version 2: Private Inheritance (✅ safe)
// ========================
class Circle : private GeoShape
{
public:
    Circle(float r) : GeoShape(r,r) {}

    void setRadius(float r){ dim1 = dim2 = r; }
    float getRadius(){ return dim1; }

    float calculateArea(){ return 22.0/7 * dim1 * dim2; }
};

// ========================
// Square - Version 2: Private Inheritance (✅ safe)
// ========================
class Square : private Rectangle
{
public:
    Square(float r) : Rectangle(r,r) {}

    void setSquareDim(float r){ dim1 = dim2 = r; }
    float getSquareDim(){ return dim1; }

    float calculateArea(){ return Rectangle::calculateArea(); }
};

// ========================
// Main
// ========================
int main()
{
    cout << "=== Using Public Inheritance (Violation Possible) ===\n";
    Circle_Public c1(5);
    c1.setDim1(5);   
    // c1.setDim2(10);   // ❌ Violation: Not a circle anymore (ellipse)
    cout << "Circle_Public Area (WRONG): " << c1.calculateArea() << endl;

    Square_Public s1(5);
    s1.setDim1(5);
    // s1.setDim2(10);   // ❌ Violation: Not a square anymore (rectangle)
    cout << "Square_Public Area (WRONG): " << s1.calculateArea() << endl;

    cout << "\n=== Using Private Inheritance (Safe) ===\n";
    Circle c2(7);
    c2.setRadius(7);   // ✅ only proper way
    cout << "Circle Area (Correct): " << c2.calculateArea() << endl;

    Square s2(4);
    s2.setSquareDim(4);  // ✅ only proper way
    cout << "Square Area (Correct): " << s2.calculateArea() << endl;

    return 0;
}
