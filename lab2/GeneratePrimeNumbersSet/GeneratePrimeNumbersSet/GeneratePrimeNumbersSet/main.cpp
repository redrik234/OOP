#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"

using namespace std;

const int MAX_PRIME = 100000000;

void OutputSet(set<int> set)
{
	copy(set.begin(), set.end(), ostream_iterator<int>(cout, " "));
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

	//OutputSet(GeneratePrimeNumbersSet(upperBound));
	set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

	cout << primeNumbers.size() << endl;

	return 0;
}