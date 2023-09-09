// OpOverloadingIncrementDecrementOp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Digit
{
    int m_digits{};

public:
    Digit(int digits) :m_digits{ digits }
    {}
    friend std::ostream& operator<<(std::ostream& out, const Digit& d);
    Digit& operator++();
    Digit& operator--();
    Digit operator++(int);
    Digit operator--(int);

};

std::ostream& operator<<(std::ostream& out, const Digit& d)
{
    out << d.m_digits;
    return out;
}

Digit& Digit::operator++()
{
    if (m_digits == 9)
        m_digits = 0;
    else
        ++m_digits;

    return *this;
}
Digit Digit::operator++(int)
{
    Digit temp{ *this };
    ++(*this);
    return temp;

}
Digit& Digit::operator--()
{
    if (m_digits == 0)
        m_digits = 9;
    else
        --m_digits;

    return *this;
}
Digit Digit::operator--(int)
{
    Digit temp{ *this };
    --(*this);
    return temp;
}

int main()
{
    Digit digit(5);

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

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
