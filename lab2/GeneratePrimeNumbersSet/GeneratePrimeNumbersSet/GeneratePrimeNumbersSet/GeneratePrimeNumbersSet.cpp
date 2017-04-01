// GeneratePrimeNumbersSet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"

using namespace std;

const int MAX_NUMBER = 100000000;
const int MIN_PRIME = 2;

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool>isPrime(upperBound + 1, true);
	set<int>primes;

	isPrime[0] = false;

	if (upperBound != 0)
	{
		isPrime[1] = false;
	}

	for (int i = MIN_PRIME; i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= upperBound; j = (i > MIN_PRIME) ? (j + 2 * i) : (j + i))
			{
				isPrime[j] = false;
			}
		}
	}

	if (upperBound >= MIN_PRIME && upperBound <= MAX_NUMBER)
	{
		for (unsigned int i = MIN_PRIME; i < isPrime.size(); ++i)
		{
			if (isPrime[i])
			{
				primes.insert(i);
			}
		}
	}
	
	return primes;
}

