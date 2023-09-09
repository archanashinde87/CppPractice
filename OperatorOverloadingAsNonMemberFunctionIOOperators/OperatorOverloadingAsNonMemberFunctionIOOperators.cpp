// OperatorOverloadingAsNonMemberFunctionIOOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Point 
{
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0) : m_x{ x }, m_y{ y }, m_z{ z }
    {}

    friend std::ostream& operator<<(std::ostream& out, const Point& point);
    friend std::istream& operator>>(std::istream& out, Point& point);
};

std::ostream& operator<<(std::ostream& out, const Point& point)
{
    out << "Point(" << point.m_x << ", " << point.m_y << ", "  << point.m_z << ")";

    return out;
}
std::istream& operator>>(std::istream& in, Point& point)
{
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;

    return in;
}


int main()
{
    Point point1{ 2.0, 3.5, 4.0 };
    Point point2{ 6.0, 7.5, 8.0 };

    std::cout << point1 << ' ' << point2 << '\n';

    std::cout << "Enter a point: ";

    Point point;
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

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
