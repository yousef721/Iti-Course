#include <iostream>
using namespace std;

class Stack
{
private:
    int Top;
    int *St;
    int Size;
    static int counter;

public:
    // Constructor
    Stack(int size = 10)
    {
        Top = 0;
        Size = size;
        St = new int[Size];
        counter++;
    };

    // Copy Constructor
    Stack(Stack &z)
    {
        Top = z.Top;
        Size = z.Size;
        St = new int[Size];
        for (int i = 0; i < Top; i++)
        {
            St[i] = z.St[i];
        }
        counter++;
    }

    // Push
    void Push(int item)
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

    // Pop
    int Pop()
    {
        int retVal;
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

    // Static Counter
    static int GetCounter()
    {
        return counter;
    }

    // Destructor
    ~Stack()
    {
        delete[] St;
        counter--;
        cout << "Stack of size " << Size << " destroyed" << endl;
    };

    // Friends
    friend void ViewContentByRef(Stack &x);
    friend void ViewContentByCopyCon(Stack x);
};

// Static member init
int Stack::counter = 0;

// By reference
void ViewContentByRef(Stack &x)
{
    cout << "Stack content (by ref): ";
    if (x.Top == 0)
    {
        cout << "[Empty]";
    }
    else
    {
        for (int i = 0; i < x.Top; i++)
        {
            cout << x.St[i] << " ";
        }
    }
    cout << endl;
}

// By copy constructor
void ViewContentByCopyCon(Stack x)
{
    cout << "Stack content (by copy): ";
    if (x.Top == 0)
    {
        cout << "[Empty]";
    }
    else
    {
        for (int i = 0; i < x.Top; i++)
        {
            cout << x.St[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    Stack s(5);
    s.Push(100);
    s.Push(200);
    s.Push(300);
    s.Push(400);

    ViewContentByRef(s);
    ViewContentByCopyCon(s);

    return 0;
}
