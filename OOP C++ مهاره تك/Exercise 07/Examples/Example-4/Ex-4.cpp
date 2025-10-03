#include <iostream>
using namespace std;

// Base class for all geometric shapes
class GeoShape
{
protected:
    float dim1;        // First dimension (e.g., base, width, or radius)
    float dim2;        // Second dimension (e.g., height or radius)
public:
    // Constructors to initialize shape dimensions
    GeoShape() : dim1(0), dim2(0) {}; 
    GeoShape(float dim) : dim1(dim), dim2(dim) {}; 
    GeoShape(float dim1, float dim2) : dim1(dim1), dim2(dim2) {}; 

    // Setter and getter methods for dimensions
    void setDim1(float dim){ dim1 = dim; }
    void setDim2(float dim){ dim2 = dim; }
    float getDim1(){ return dim1; }
    float getDim2(){ return dim2; }

    // Virtual function for polymorphism (should be overridden in derived classes)
    virtual float calculateArea()
    {
        return 0; // Default area is 0 for generic shape
    }

    ~GeoShape(){};
};

// Derived class for Triangle (inherits publicly)
class Triangle : public GeoShape
{     
public:
    Triangle(float b, float h) : GeoShape(b, h) {}; 

    // Override area calculation: Area = 0.5 * base * height
    float calculateArea()
    {
        return 0.5 * dim1 * dim2;
    }

    ~Triangle(){};
};

// Derived class for Rectangle (inherits publicly)
class Rectangle : public GeoShape
{     
public:
    Rectangle(float x, float y) : GeoShape(x, y) {}; 

    // Override area calculation: Area = width * height
    float calculateArea()
    {
        return dim1 * dim2;
    }

    ~Rectangle(){};
};

// Circle inherits privately from GeoShape
// Reason: Circle is NOT a "two-dimensional shape with width & height" in the same sense as Rectangle.
// It only needs one dimension (radius). We reuse GeoShape for storing radius, but hide it from outside.
class Circle : private GeoShape
{     
public:
    Circle(float r) : GeoShape(r) {}; 

    // Set radius (both dim1 and dim2 are set to radius)
    void setRadius(float r){ dim1 = dim2 = r; }
    float getRadius(){ return dim1; }

    // Override area calculation: Area = π * r^2
    float calculateArea()
    {
        return 22.0/7 * dim1 * dim2;
    }

    ~Circle(){};
};

// Square inherits privately from Rectangle
// Reason: A Square IS a special case of Rectangle, 
// but we want to restrict access so the user cannot set width and height differently.
// Private inheritance hides Rectangle's interface (like setDim1, setDim2) from outside.
class Square : private Rectangle
{     
public:
    Square(float r) : Rectangle(r,r){}; 

    // Set side length (force both dimensions equal)
    void setSquareDim(float r){ dim1 = dim2 = r; }
    float getSquareDim(){ return dim1; }

    // Override area calculation (same as Rectangle but restricted to equal sides)
    float calculateArea()
    {
        return Rectangle::calculateArea();
    }

    ~Square(){};
};

int main()
{
    // Create objects of each shape
    Triangle t(10, 5);       // base=10, height=5
    Rectangle r(4, 6);       // width=4, height=6
    Circle c(7);             // radius=7
    Square s(4);             // side=4

    // Print calculated areas
    cout << "Triangle Area: " << t.calculateArea() << endl;
    cout << "Rectangle Area: " << r.calculateArea() << endl;
    cout << "Circle Area: " << c.calculateArea() << endl;
    cout << "Square Area: " << s.calculateArea() << endl;

    return 0;
}
