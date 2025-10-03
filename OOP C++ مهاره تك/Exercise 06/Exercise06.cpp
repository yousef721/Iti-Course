#include <iostream>
using namespace std;

class Shape
{
private:
    int color;
public:
    Shape() {}
    Shape(int c): color(c) {}
    ~Shape() {}

    // function for polymorphism
    void Draw() {
        cout << "Drawing a generic shape" << endl;
    }
};

class Point 
{
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}
    int GetX() { return x; }
    int GetY() { return y; }
};

class Line : public Shape
{
private:
    Point start, end;
public:
    Line() : Shape(), start(), end() {}
    Line(int x1, int y1, int x2, int y2, int c): Shape(c), start(x1,y1), end(x2,y2) {} 

    // Override function
    void Draw() {
        cout << "Drawing Line from (" << start.GetX() << "," << start.GetY()
             << ") to (" << end.GetX() << "," << end.GetY() << ")" << endl;
    }
};

class Rect : public Shape
{
    Point ul, lr;
public:
    Rect() : Shape(), ul(), lr() {}
    Rect(int x1, int y1, int x2, int y2, int c): Shape(c), ul(x1,y1), lr(x2,y2) {}

    // Override function
    void Draw() {
        cout << "Drawing Rectangle from (" << ul.GetX() << "," << ul.GetY()
             << ") to (" << lr.GetX() << "," << lr.GetY() << ")" << endl;
    }
};

class Circle : public Shape
{
    Point center;
    int radius;
public:
    Circle() : Shape(), center(), radius(0) {}
    Circle(int r, int x, int y, int c): Shape(c), center(x,y), radius(r) {}

    // Override function
    void Draw() {
        cout << "Drawing Circle at (" << center.GetX() << "," << center.GetY()
             << ") with radius " << radius << endl;
    }
};

int main()
{
    Line l(0,0,10,10,1);
    Rect r(0,0,5,5,2);
    Circle c(7,3,3,3);

    l.Draw();
    r.Draw();
    c.Draw();

    return 0;
}

