// GeneratePrimeNumbersSet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"

using namespace std;

const int MAX_NUMBER = 100000000;
const int MIN_PRIME = 2;

vector<bool> GetPrimeNumbers(int & upperBound)
{
	vector<bool>isPrime(upperBound + 1, true);

	isPrime[0] = false;

	if (upperBound != 0)
	{
		isPrime[1] = false;
	}

	for (int i = MIN_PRIME; i*i <= upperBound; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= upperBound; j = (i > MIN_PRIME) ? (j + 2 * i) : (j + i))
			{
				isPrime[j] = false;
			}
		}
	}
	return isPrime;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int>primes;

	vector<bool> isPrime = GetPrimeNumbers(upperBound);

	if (upperBound >= MIN_PRIME && upperBound <= MAX_NUMBER)
	{
		for (int i = MIN_PRIME; i <= upperBound; ++i)
		{
			if (isPrime[i])
			{
				primes.insert(i);
			}
		}
	}

	return primes;
}
