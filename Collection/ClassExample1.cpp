// Collection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Point2d
{
    double m_x{};
    double m_y{};

public:
    
    Point2d(double x=0.0, double y=0.0) : m_x{ x }, m_y{y}
    {}

    void print()
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")" << '\n';
    }

    double distanceTo(const Point2d& other) const
    {
        return (std::sqrt((m_x - other.m_x) * (m_x - other.m_x) + (m_y - other.m_y) * (m_y - other.m_y)));
    }

    friend double distanceFrom(const Point2d& first, const Point2d& second);
   
};

double distanceFrom(const Point2d& first, const Point2d& second)
{
    return (std::sqrt((first.m_x - second.m_x) * (first.m_x - second.m_x) + (first.m_y - second.m_y) * (first.m_y - second.m_y)));
}
int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

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
