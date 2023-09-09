// SpaceShipOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numeric> // for std::gcd

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
	friend bool operator==(const Fraction& f1, const Fraction& f2);
	friend bool operator!=(const Fraction& f1, const Fraction& f2);
	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f1, const Fraction& f2);
	friend bool operator<=(const Fraction& f1, const Fraction& f2);
	friend bool operator>=(const Fraction& f1, const Fraction& f2);

	//friend bool operator<=>(const Fraction& f1, const Fraction& f2); // C++20 feature

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}
bool operator==(const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator);
}
bool operator!=(const Fraction& f1, const Fraction& f2)
{
	return (!operator==(f1,f2));
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	return(f1.m_numerator * f2.m_denominator < f2.m_numerator* f1.m_denominator);
}
bool operator>(const Fraction& f1, const Fraction& f2)
{
	return operator<(f2, f1);
}
bool operator<=(const Fraction& f1, const Fraction& f2)
{
	return !(operator>(f1, f2));
}
bool operator>=(const Fraction& f1, const Fraction& f2)
{
	return !(operator<(f1, f2));
}

//Spaceship Operator
//bool operator<=>(const Fraction& f1, const Fraction& f2)
//{
//}


int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
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
