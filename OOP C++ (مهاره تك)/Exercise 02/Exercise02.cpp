#include <iostream>

// Complete complex class
class Complex
{
    int Real;
    int Img;

public:
    // Default constructor
    Complex() : Real(0), Img(0) {}

    // Parameterized constructor
    Complex(int real, int img) : Real(real), Img(img) {}

    // Setters
    void SetReal(int real) { Real = real; }
    void SetImg(int img) { Img = img; }

    // Set full complex number
    void SetComplexNumber(int real, int img)
    {
        Real = real;
        Img = img;
    }

    // Add two complex numbers
    Complex Add(Complex other)
    {
        return Complex(Real + other.Real, Img + other.Img);
    }

    // Subtract two complex numbers
    Complex Subtract(Complex other)
    {
        return Complex(Real - other.Real, Img - other.Img);
    }

    // Print in math style (a + bi)
    void Print()
    {
        std::cout << Real;
        if (Img >= 0)
            std::cout << " + " << Img << "i";
        else
            std::cout << " - " << -Img << "i";
        std::cout << std::endl;
    }

    // Destructor
    ~Complex()
    {
        std::cout << "Complex object destroyed" << std::endl;
    }
};
// Stack class
class Stack
{
private:
    int Top;
    int *St;
    int Size;
    static int counter;   // Static member to count objects

public:
    // Constructor
    Stack(int size = 10)
    {
        Top = 0;
        Size = size;
        St = new int[Size];
        counter++;
    };

    // Push item to stack
    void Push(int item)
    {
        if (Size == Top)
        {
            std::cout << "This Stack is full" << std::endl;
        }
        else
        {
            St[Top] = item;
            Top++;
        }
    }

    // Pop item from stack
    int Pop()
    {
        int retVal;
        if (Top == 0)
        {
            std::cout << "This Stack is Empty" << std::endl;
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
        std::cout << "Stack destroyed" << std::endl;
    };
};

// Define static member
int Stack::counter = 0;

int main()
{
    // Part 1
    #pragma region : ComplexNumber
    
        Complex myComp1, myComp2, resultComp;

        std::cout << "Please Enter Complex Number 1 : " << std::endl;
        int real1,img1;
        std::cout << "Real =  ";
        std::cin >> real1;
        std::cout << "Imaginary =  ";
        std::cin >> img1;
        myComp1.SetComplexNumber(real1,img1);

        std::cout << "Please Enter Complex Number 2 : " << std::endl;
        int real2,img2;
        std::cout << "Real =  ";
        std::cin >> real2;
        std::cout << "Imaginary =  ";
        std::cin >> img2;
        myComp2.SetReal(real2);

        // Print input
        std::cout << "\nYou entered:" << std::endl;
        std::cout << "Complex 1 = ";
        myComp1.Print();
        std::cout << "Complex 2 = ";
        myComp2.Print();

    #pragma endregion
    // Part 2
    #pragma region : Stack
        Stack s1(2);
        Stack s2(3);

        std::cout << "\nNumber of Stacks = " << Stack::GetCounter() << std::endl;

        s1.Push(10);
        s1.Push(20);
        s1.Push(30); // will print full

        std::cout << "Pop: " << s1.Pop() << std::endl;
        std::cout << "Pop: " << s1.Pop() << std::endl;
        std::cout << "Pop: " << s1.Pop() << std::endl; // will print empty

        std::cout << "Number of Stacks (before end) = " << Stack::GetCounter() << std::endl;
    #pragma endregion

    return 0;
}
