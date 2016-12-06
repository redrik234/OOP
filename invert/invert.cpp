#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const size_t matrixSize = 3;
typedef double Matrix3x3[matrixSize][matrixSize];
typedef double Matrix2x2[2][2];

void FillMatrix(istream & inputFile, Matrix3x3 matrix)
{
	for (size_t i = 0; i < matrixSize; ++i)
	{
		for (size_t j = 0; j < matrixSize; ++j)
		{
			inputFile >> matrix[i][j];
		}
	}
}

void OutputMatrix(ostream & output, Matrix3x3 matrix)
{
	for (size_t i = 0; i < matrixSize; ++i)
	{
		for (size_t j = 0; j < matrixSize; ++j)
		{
			if (matrix[i][j] == -0.0f)
				matrix[i][j] = 0.0f;
			output << fixed << setprecision(3) << matrix[i][j] << " ";
		}

		output << endl;
	}
}

double ReceiveMinor(Matrix3x3 matrix, size_t row, size_t col)
{
	Matrix2x2 minorMatrix;

	for (size_t m = 0, i = 0; i < matrixSize; ++i)
	{
		if (i != row)
		{
			for (size_t n = 0, j = 0; j < matrixSize; ++j)
			{
				if (j != col)
				{
					minorMatrix[m][n] = matrix[i][j];
					++n;
				}
			}

			++m;
		}
	}

	return (minorMatrix[0][0] * minorMatrix[1][1] - minorMatrix[1][0] * minorMatrix[0][1]);
}

double ReceiveDeterminant(Matrix3x3 matrix)
{
	double determinantMatrix = 0;

	for (size_t i = 0; i < matrixSize; ++i)
	{
		determinantMatrix += pow(-1, i)* matrix[i][0] * ReceiveMinor(matrix, i, 0);
	}

	return determinantMatrix;
}

bool ReceiveInvertiableMatrix(Matrix3x3 matrix, Matrix3x3 invertibleMatrix)
{
	double det = ReceiveDeterminant(matrix);

	if (det == 0)
	{
		return false;
	}

	for (size_t i = 0; i < matrixSize; ++i)
	{
		for (size_t j = 0; j < matrixSize; ++j)
		{
			invertibleMatrix[j][i] = pow(-1, (i + j)) * ReceiveMinor(matrix, i, j) / det;
			
		}
	}

	return true;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count:\n"
				<< "Usage: invert.exe <matrix file>\n";
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	Matrix3x3 matrix;

	FillMatrix(input, matrix);

	Matrix3x3 invertibleMatrix;

	if (!ReceiveInvertiableMatrix(matrix, invertibleMatrix))
	{
		cout << "Invertible matrix doesn't exist" << endl;
		return 1;
	}

	OutputMatrix(cout, invertibleMatrix);
	return 0;
}