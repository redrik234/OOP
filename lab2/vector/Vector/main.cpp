// Vector.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

int main()
{
	vector<double> numbers = ReadVector(cin);
	ProcessVector(numbers);
	SortVector(numbers);
	OutVector(cout, numbers);
	return 0;
}

