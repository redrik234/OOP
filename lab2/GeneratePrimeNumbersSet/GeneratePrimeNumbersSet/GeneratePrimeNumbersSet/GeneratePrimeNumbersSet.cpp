// GeneratePrimeNumbersSet.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"

using namespace std;

static const int MAX_NUMBER = 100000000;
static const int MIN_PRIME = 2;

vector<bool> CreateSieve(const int & upperBound)
{
	vector<bool> isPrime(upperBound + 1, true);

	isPrime[0] = false;

	if (upperBound != 0)
	{
		isPrime[1] = false;
	}

	for (int i = MIN_PRIME; i * i <= upperBound; ++i)
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

	if (upperBound >= MIN_PRIME && upperBound <= MAX_NUMBER)
	{
		vector<bool> isPrime = CreateSieve(upperBound);

		for (int i = MIN_PRIME; i <= upperBound; ++i)
		{
			if (isPrime[i])
			{
				primes.insert(primes.end(), i);
			}
		}
	}

	return primes;
}