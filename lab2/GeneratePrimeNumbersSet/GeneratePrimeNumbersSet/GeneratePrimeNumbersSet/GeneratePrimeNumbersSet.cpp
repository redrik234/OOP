// GeneratePrimeNumbersSet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"

using namespace std;

const int MAX_NUMBER = 100000000;
const int MIN_PRIME = 2;

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool>numbers(upperBound + 1, true);
	set<int>primes;

	numbers[0] = false;

	if (upperBound != 0)
	{
		numbers[1] = false;
	}

	for (int i = MIN_PRIME; i <= upperBound / i; ++i)
	{
		if (numbers[i])
		{
			for (int j = i * i; j <= upperBound; j = (i > MIN_PRIME) ? (j + 2 * i) : (j + i))
			{
				numbers[j] = false;
			}
		}
	}

	if (upperBound >= MIN_PRIME && upperBound <= MAX_NUMBER)
	{
		for (unsigned int i = MIN_PRIME; i < numbers.size(); ++i)
		{
			if (numbers[i])
			{
				primes.insert(i);
			}
		}
	}
	
	return primes;
}

