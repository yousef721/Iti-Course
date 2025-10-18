#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}
    int GetX() { return x; }
    int GetY() { return y; }
};

class Line {
    Point start, end; // Composition: Line "has" two Points (start and end)
public:
    Line() : start(), end() {}
    Line(int x1, int y1, int x2, int y2): start(x1,y1), end(x2,y2) {} 
    void Draw() {
        cout << "Drawing Line from (" << start.GetX() << "," << start.GetY()
             << ") to (" << end.GetX() << "," << end.GetY() << ")" << endl;
    }
};

class Rect {
    Point ul, lr; // Composition: Rectangle "has" two Points
public:
    Rect() : ul(), lr() {}
    Rect(int x1, int y1, int x2, int y2): ul(x1,y1), lr(x2,y2) {}
    void Draw() {
        cout << "Drawing Rectangle from (" << ul.GetX() << "," << ul.GetY()
             << ") to (" << lr.GetX() << "," << lr.GetY() << ")" << endl;
    }
};

class Circle {
    Point center; // Composition: Circle "has" a Point as its center
    int radius;
public:
    Circle() : center(), radius(0) {}
    Circle(int r, int x, int y): center(x,y), radius(r) {}
    void Draw() {
        cout << "Drawing Circle at (" << center.GetX() << "," << center.GetY()
             << ") with radius " << radius << endl;
    }
};
