#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const size_t MATRIX_SIZE = 3;
const size_t MATRIX_SIZE2 = 2;

typedef double Matrix3x3[MATRIX_SIZE][MATRIX_SIZE];
typedef double Matrix2x2[MATRIX_SIZE2][MATRIX_SIZE2];

bool FillMatrix(istream &inputFile, Matrix3x3 matrix)
{
	double number;

	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			if (!(inputFile >> number))
			{
				return false;
			}
			matrix[i][j] = number;
		}
	}
	return true;
}

void PrintMatrix(ostream &output, Matrix3x3 matrix)
{
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			if (matrix[i][j] == -0.0f)
			{
				matrix[i][j] = 0.0f;
			}
			output << fixed << setprecision(3) << matrix[i][j] << " ";
		}

		output << endl;
	}
}

double ReceiveMinor(Matrix3x3 matrix, size_t row, size_t col)
{
	Matrix2x2 minorMatrix;

	for (size_t m = 0, i = 0; i < MATRIX_SIZE; ++i)
	{
		if (i != row)
		{
			for (size_t n = 0, j = 0; j < MATRIX_SIZE; ++j)
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

	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		determinantMatrix += pow(-1, i) * matrix[i][0] * ReceiveMinor(matrix, i, 0);
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

	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
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

	if (!FillMatrix(input, matrix))
	{
		cout << "Wrong input matrix\n";
		return 1;
	}

	Matrix3x3 invertibleMatrix;

	if (!ReceiveInvertiableMatrix(matrix, invertibleMatrix))
	{
		cout << "Invertible matrix doesn't exist" << endl;
		return 1;
	}

	PrintMatrix(cout, invertibleMatrix);
	return 0;
}
