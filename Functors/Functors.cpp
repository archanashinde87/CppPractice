// Functors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Accumulator
{
private:
    int m_counter{ 0 };

public:
    int operator() (int i) { return (m_counter += i); }

    void reset() { m_counter = 0; }
};

int main()
{
    Accumulator acc{};
    std::cout << acc(1) << '\n'; 
    std::cout << acc(3) << '\n'; 

    Accumulator acc2{};
    std::cout << acc2(10) << '\n'; 
    std::cout << acc2(20) << '\n';

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
