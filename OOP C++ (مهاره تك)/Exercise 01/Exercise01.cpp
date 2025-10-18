#include <iostream>

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

    ~Complex() {}
};

int main()
{
    Complex myComp1, myComp2, resultComp;

    std::cout << "Please Enter Complex Number 1 : " << std::endl;
    std::cout << "Real =  ";
    int real1;
    std::cin >> real1;
    myComp1.SetReal(real1);
    std::cout << "Imaginary =  ";
    int img1;
    std::cin >> img1;
    myComp1.SetImg(img1);

    std::cout << "Please Enter Complex Number 2 : " << std::endl;
    std::cout << "Real =  ";
    int real2;
    std::cin >> real2;
    myComp2.SetReal(real2);
    std::cout << "Imaginary =  ";
    int img2;
    std::cin >> img2;
    myComp2.SetImg(img2);

    // Print input
    std::cout << "\nYou entered:" << std::endl;
    std::cout << "Complex 1 = "; myComp1.Print();
    std::cout << "Complex 2 = "; myComp2.Print();

    // Add
    resultComp = myComp1.Add(myComp2);
    std::cout << "Sum = "; resultComp.Print();

    // Subtract
    resultComp = myComp1.Subtract(myComp2);
    std::cout << "Difference = "; resultComp.Print();

    return 0;
}
