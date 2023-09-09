// OverloadingSubscriptOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<string_view>

struct StudentGrade
{
    std::string m_name{};
    char m_grade{};

};

class GradeMap
{
    std::vector<StudentGrade> m_map{};
public:
	char& operator[](std::string_view name)
	{
		auto found{ std::find_if(m_map.begin(), m_map.end(), [&](const auto& student) {return student.m_name == name; }) };
		if (found != m_map.end())
		{
			return found->m_grade;
		}
		m_map.push_back({ std::string(name) });
		return m_map.back().m_grade;
	}
};
int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

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
