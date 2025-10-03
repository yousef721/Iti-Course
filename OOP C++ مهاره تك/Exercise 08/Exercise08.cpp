#include <iostream>
using namespace std;

#pragma region : Part 1 GeoShape
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

    virtual float calculateArea() = 0;
    ~GeoShape(){}
};

class Triangle : public GeoShape
{
public:
    Triangle(float b, float h) : GeoShape(b, h) {}
    float virtual calculateArea(){ return 0.5 * dim1 * dim2; }
};

class Rectangle : public GeoShape
{
public:
    Rectangle(float x, float y) : GeoShape(x, y) {}
    float virtual calculateArea(){ return dim1 * dim2; }
};

class Circle : public GeoShape
{
public:
    Circle(float r) : GeoShape(r,r) {}

    void setRadius(float r){ dim1 = dim2 = r; }
    float getRadius(){ return dim1; }

    float virtual calculateArea(){ return 22.0/7 * dim1 * dim2; }
};

class Square : public Rectangle
{
public:
    Square(float r) : Rectangle(r,r) {}

    void setSquareDim(float r){ dim1 = dim2 = r; }
    float getSquareDim(){ return dim1; }

    float calculateArea(){ return Rectangle::calculateArea(); }
};

// Standalone Function
float sumAreas(GeoShape *p1, GeoShape *p2, GeoShape *p3)
{
    return p1->calculateArea() + p2->calculateArea() + p3->calculateArea();
}
#pragma endregion

#pragma region : Part 2 Stack
// Stack With template class
template<class T>
class Stack
{
private:
    int Top;
    T *St;
    int Size;
    static int counter;   // Static member to count objects

public:
    // Constructor
    Stack(int size = 10)
    {
        Top = 0;
        Size = size;
        St = new T[Size];
        counter++;
    };

    // Push item to stack
    void Push(T item)
    {
        if (Size == Top)
        {
            cout << "This Stack is full" << endl;
        }
        else
        {
            St[Top] = item;
            Top++;
        }
    }

    // Pop item from stack
    T Pop()
    {
        T retVal;
        if (Top == 0)
        {
            cout << "This Stack is Empty" << endl;
            retVal = -1;
        }
        else
        {
            Top--;
            retVal = St[Top];
        }
        return retVal;
    }

    // Static function to return number of stacks
    static int GetCounter()
    {
        return counter;
    }

    // Destructor
    ~Stack()
    {
        delete[] St;
        counter--;
        cout << "Stack destroyed" << endl;
    };
};

// Static member definition
template<class T>
int Stack<T>::counter = 0;

#pragma endregion

int main()
{
    // Part 1
    #pragma region 
        Triangle myT(20, 10);
        Rectangle myR(2, 5);
        Circle myC(5);

        cout << "Sum of areas = " << sumAreas(&myT, &myR, &myC) << endl;
    #pragma endregion

    cout << "----------------------------------" << endl;

    // Part 2
    #pragma region 
        // Test Stack<int>
        Stack<int> s1(5);
        s1.Push(10);
        s1.Push(20);
        cout << "Popped from int stack: " << s1.Pop() << endl;

        // Test Stack<string>
        Stack<string> s2(3);
        s2.Push("Hello");
        s2.Push("World");
        cout << "Popped from string stack: " << s2.Pop() << endl;

        cout << "Active stacks count = " << Stack<int>::GetCounter() << endl;
    #pragma endregion

    return 0;
}
