// OperatorOverloadingAsMemberFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Point
{
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x{ x }, m_y{ y }, m_z{ z }
    {}
    Point operator+() const;
    Point operator-() const;
    bool operator!() const;

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

Point Point::operator+() const
{
    return *this;
}
Point Point::operator-() const
{
    return { -m_x, -m_y, -m_z };
}
bool Point::operator!() const
{
    return ( m_x==0.0 && m_y==0.0 && m_z==0.0 );
}

int main()
{
    Point point{}; // use default constructor to set to (0.0, 0.0, 0.0)

    if (!point)
        std::cout << "point is set at the origin.\n";
    else
        std::cout << "point is not set at the origin.\n";

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
