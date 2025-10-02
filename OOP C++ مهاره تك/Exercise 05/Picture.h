#include "Shapes.h"

class Picture
{
private:
    int cNum;
    int rNum;
    int lNum;
    Circle *pCircle;
    Rect *pRectangle;
    Line *pLine;
public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircle(), pRectangle(), pLine(){};
    Picture(int c, int r, int l, Circle *pC, Rect *pR, Line *pL) : cNum(c), rNum(r), lNum(l), pCircle(pC), pRectangle(pR), pLine(pL){};

    void setCircle(int c, Circle *cPtr){cNum = c; pCircle = cPtr;}
    void setRectangle(int r, Rect *rPtr){rNum = r; pRectangle = rPtr;}
    void setLine(int l, Line *lPtr){lNum = l; pLine = lPtr;}

    void Paint()
    {
        int i;
        // Circles
        for (i = 0; i < cNum; i++) { pCircle[i].Draw(); }
        // Rectangles
        for (i = 0; i < rNum; i++) { pRectangle[i].Draw(); }
        // Lines
        for (i = 0; i < lNum; i++) { pLine[i].Draw(); }
    }

    ~Picture(){};
};
