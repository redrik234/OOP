// lab6(solve4).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solve4.h"

int main()
{
	EquationRoots equationRoots;

	std::vector<double> numbers;
	double number;

	while (std::cin >> number && !std::cin.eof())
	{
		if (numbers.size() != 5)
		{
			numbers.push_back(number);
		}
	}

	try
	{
		if (numbers.size() != 5)
		{
			throw std::domain_error("Invalid arguements count.\nCount of arguements must be equal to 5.");
		}

		equationRoots = Solve4(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
	}
	catch (std::invalid_argument const &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::domain_error const &e)
	{
		std::cout << e.what() << std::endl;
	}

	PrintRoots(equationRoots, std::cout);
	return 0;

}