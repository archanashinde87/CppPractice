// OpOverloadingAsNonMemberComparisonOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Cents
{
    int m_cents{};

public:
    Cents(int cents) :m_cents{ cents }
    {}
    friend bool operator==(const Cents& cent1, const Cents& cent2);
    friend bool operator!=(const Cents& cent1, const Cents& cent2);
    friend bool operator<(const Cents& cent1, const Cents& cent2);
    friend bool operator>(const Cents& cent1, const Cents& cent2);
    friend bool operator<=(const Cents& cent1, const Cents& cent2);
    friend bool operator>=(const Cents& cent1, const Cents& cent2);

};

bool operator==(const Cents& cent1, const Cents& cent2)
{
    return (cent1.m_cents == cent2.m_cents);
}
bool operator!=(const Cents& cent1, const Cents& cent2)
{
    //return (cent1.m_cents != cent2.m_cents);
    return (!operator==(cent1, cent2));
}
bool operator<(const Cents& cent1, const Cents& cent2)
{
    return (cent1.m_cents < cent2.m_cents);
}
bool operator>(const Cents& cent1, const Cents& cent2)
{
   // return (cent1.m_cents > cent2.m_cents);
    return (operator<(cent2, cent1));
}
bool operator<=(const Cents& cent1, const Cents& cent2)
{
    //return (cent1.m_cents <= cent2.m_cents);
    return (!operator>(cent1, cent2));
}
bool operator>=(const Cents& cent1, const Cents& cent2)
{
    //return (cent1.m_cents >= cent2.m_cents);
    return (!operator<(cent1, cent2));
}

int main()
{
    Cents dime{ 10 };
    Cents nickel{ 5 };

    if (nickel > dime)
        std::cout << "a nickel is greater than a dime.\n";
    if (nickel >= dime)
        std::cout << "a nickel is greater than or equal to a dime.\n";
    if (nickel < dime)
        std::cout << "a dime is greater than a nickel.\n";
    if (nickel <= dime)
        std::cout << "a dime is greater than or equal to a nickel.\n";
    if (nickel == dime)
        std::cout << "a dime is equal to a nickel.\n";
    if (nickel != dime)
        std::cout << "a dime is not equal to a nickel.\n";

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
