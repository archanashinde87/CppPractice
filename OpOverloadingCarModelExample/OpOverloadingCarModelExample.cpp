// OpOverloadingCarModelExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Car
{
    std::string m_make{};
    std::string m_model{};

public:
    Car(std::string make, std::string model) : m_make{ make }, m_model{ model }
    {}
    friend std::ostream& operator<<(std::ostream& out, const Car& car);
    friend bool operator<(const Car& car1, const Car& car2);
};

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    out << '(' << car.m_make << ", " << car.m_model << ')';
    return out;
}

bool operator<(const Car& car1, const Car& car2)
{
    if (car1.m_make == car2.m_make)
        return(car1.m_model < car2.m_model);
    else
        return (car1.m_make < car2.m_make);
}

int main()
{
    std::vector<Car> cars{
      { "Toyota", "Corolla" },
      { "Honda", "Accord" },
      { "Toyota", "Camry" },
      { "Honda", "Civic" }
    };

    std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

    for (const auto& car : cars)
        std::cout << car << '\n'; // requires an overloaded operator<<

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
