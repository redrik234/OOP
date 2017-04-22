#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"
#include <algorithm>

using namespace std;

static const int MAX_PRIME = 100000000;
static const int BOUNDARY_FOR_OUTPUT = 550;

void OutputPrimeNumberSet(const set<int> & set)
{
	if (set.size() > 100)
	{
		char ch;
		cout << "Print all numbers?(y/n)";
		cin >> ch;
		if (ch == 'y')
		{
			copy(set.begin(), set.end(), ostream_iterator<int>(cout, " "));
		}
		if (ch == 'n')
		{
			copy_if(set.begin(), set.end(), ostream_iterator<int>(cout, " "), [](int x) { return x < BOUNDARY_FOR_OUTPUT; });
			cout << "Number of primes: " << set.size() << endl;
		}
	}
	else
	{
		copy(set.begin(), set.end(), ostream_iterator<int>(cout, " "));
	}
}

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		cout << "Invalid arguents count\n"
			<< "Usage: GeneratePrimeNumbersSet.exe <upperBound>";
		return 1;
	}

	int upperBound;

	upperBound = atoi(argv[1]);

	if ((upperBound == 0 && *argv[1] != '0') || upperBound > MAX_PRIME || upperBound < 0)
	{
		cout << "Invalid argument <upperBound>\n";
		return 1;
	}

	auto primeNumbers = GeneratePrimeNumbersSet(upperBound);

	OutputPrimeNumberSet(primeNumbers);

	return 0;
}
