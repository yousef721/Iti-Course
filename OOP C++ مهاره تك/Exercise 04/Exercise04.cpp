#include <iostream>
using namespace std;

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

    // Operator +=
    Complex operator +=(Complex c)
    {
        Real += c.Real;
        Img += c.Img;
        return *this;
    }

    // Operator +
    Complex operator +(Complex c)
    {
        return Complex(Real + c.Real, Img + c.Img);
    }

    // Operator -
    Complex operator -(Complex c)
    {
        return Complex(Real - c.Real, Img - c.Img);
    }

    // Operator + with float
    Complex operator +(float n)
    {
        return Complex(Real + n, Img);
    }

    // Operator - with float
    Complex operator -(float n)
    {
        return Complex(Real - n, Img);
    }

    // Prefix ++
    Complex operator ++()
    {
        Real++;
        return *this;
    }

    // Postfix ++
    Complex operator++(int)
    {
        Complex temp = *this; 
        Real++;
        return temp;          
    }

    // Casting operator: convert Complex -> float (returns Real part)
    operator float()
    {
        return (float)Real;
    }

    // Friend Function
    friend Complex operator +(float n, Complex c);
    friend Complex operator -(float n, Complex c);

    // Destructor
    ~Complex()
    {
        std::cout << "Complex object destroyed" << std::endl;
    }
};

// Friend functions
Complex operator +(float n, Complex c)
{
    return Complex(c.Real + n, c.Img);
}
Complex operator -(float n, Complex c)
{
    return Complex(n - c.Real, -c.Img);
}

int main()
{
    Complex c1(4,6);
    Complex c2(2,4);

    cout << "Original values:\n";
    c1.Print();
    c2.Print();

    // Test prefix ++
    cout << "\nPrefix ++ (before): ";
    c1.Print();
    ++c1;
    cout << "Prefix ++ (after): ";
    c1.Print();

    // Test postfix ++
    cout << "\nPostfix ++ (before): ";
    c2.Print();
    Complex temp = c2++;
    cout << "Returned value from postfix: ";
    temp.Print();
    cout << "Postfix ++ (after): ";
    c2.Print();

    // Test casting to float
    cout << "\nCasting Complex to float (returns Real part):\n";
    float f1 = (float)c1;
    cout << "c1 as float = " << f1 << endl;

    float f2 = c2;  // implicit cast
    cout << "c2 as float = " << f2 << endl;

    return 0;
}
