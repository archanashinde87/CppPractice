// OperatorOverloadingAsNonMemberFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<numeric>
#include <limits>

class Fraction
{
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{ numerator }, m_denominator{ denominator }
    {
        reduce();
    }
    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << '\n';
    }

    void reduce()
    {
        int gcd{ std::gcd(m_numerator, m_denominator) };
        if (gcd) // Make sure we don't try to divide by 0
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2);
    friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2);
    friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2);

    friend Fraction operator*(const Fraction& fraction, int value);
    friend Fraction operator*(int value, const Fraction& f1);
    friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);

};

Fraction operator+(const Fraction& fraction1, const Fraction& fraction2)
{
    return{ fraction1.m_numerator + fraction2.m_numerator , fraction1.m_denominator + fraction2.m_denominator };
}
Fraction operator-(const Fraction& fraction1, const Fraction& fraction2)
{
    return{ fraction1.m_numerator - fraction2.m_numerator , fraction1.m_denominator - fraction2.m_denominator };
}
Fraction operator/(const Fraction& fraction1, const Fraction& fraction2)
{
    return{ fraction1.m_numerator * fraction2.m_denominator , fraction1.m_denominator * fraction2.m_numerator };
}

Fraction operator*(const Fraction& fraction, int value)
{
    return{ fraction.m_numerator * value, fraction.m_denominator };
}
Fraction operator*(int value, const Fraction& f1)
{
    return f1 * value;
}
Fraction operator*(const Fraction& fraction1, const Fraction& fraction2)
{
    return{ fraction1.m_numerator * fraction2.m_numerator , fraction1.m_denominator* fraction2.m_denominator };
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.m_numerator << "/" << fraction.m_denominator;
    return out;
}
std::istream& operator>>(std::istream& in, Fraction& fraction)
{
    in >> fraction.m_numerator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> fraction.m_denominator;
    fraction.reduce();
    return in;
}

int main()
{
    Fraction f1{ 1, 4 };
    f1.print();

    Fraction f2{ 1, 2 };
    f2.print();

    Fraction f3{ 2, 5 };
    f3.print();

    Fraction f4{ 3, 8 };
    f4.print();

    Fraction f5{ f3 * f4 };
    f5.print();

    Fraction f6{ f3 * 2 };
    f6.print();

    Fraction f7{ 2 * f4 };
    f7.print();

    Fraction f8{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
    f8.print();

    Fraction fAdd{ f3 + f4 };
    fAdd.print();

    Fraction fSubstract{ f3 - f4 };
    fSubstract.print();

    Fraction fDivide{ f3 / f4 };
    fDivide.print();


    Fraction f9;
    std::cout << "Enter fraction 1: ";
    std::cin >> f9;

    Fraction f10;
    std::cout << "Enter fraction 2: ";
    std::cin >> f10;

    std::cout << f9 << " * " << f10 << " is " << f9 * f10 << '\n';

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
