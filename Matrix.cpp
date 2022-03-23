#include "stdafx.h"

Matrix::Matrix()
{
	// create matrix(size) for array (made within parent Matrix class)
	this->createMatrix(16);
} 

Matrix::~Matrix()
{
	delete[] this->matrixArray;
}

void Matrix::identityMatrix()
{
	// create matrix(size) for array (made within parent Matrix class)
	this->createMatrix(16);

	// Set values in matrix (within parent class Matrix.cpp)
	this->matrixArray[0] = 1;
	this->matrixArray[1] = 0;
	this->matrixArray[2] = 0;
	this->matrixArray[3] = 0;
	this->matrixArray[4] = 0;
	this->matrixArray[5] = 1;
	this->matrixArray[6] = 0;
	this->matrixArray[7] = 0;
	this->matrixArray[8] = 0;
	this->matrixArray[9] = 0;
	this->matrixArray[10] = 1;
	this->matrixArray[11] = 0;
	this->matrixArray[12] = 0;
	this->matrixArray[13] = 0;
	this->matrixArray[14] = 0;
	this->matrixArray[15] = 1;
}

// Create 3x1 Matrix
Matrix::Matrix(float r1, float r2, float r3)
{
	// create matrix(size) for array (made within parent Matrix class)
	this->createMatrix(16);

	// Set values in matrix (within parent class Matrix.cpp)
	this->matrixArray[0] = r1;
	this->matrixArray[1] = 0;
	this->matrixArray[2] = 0;
	this->matrixArray[3] = 0;
	this->matrixArray[4] = r2;
	this->matrixArray[5] = 0;
	this->matrixArray[6] = 0;
	this->matrixArray[7] = 0;
	this->matrixArray[8] = r3;
	this->matrixArray[9] = 0;
	this->matrixArray[10] = 0;
	this->matrixArray[11] = 0;
	this->matrixArray[12] = 0;
	this->matrixArray[13] = 0;
	this->matrixArray[14] = 0;
	this->matrixArray[15] = 1;
}

// Create 2x2 Matrix
Matrix::Matrix(float r1, float r2, float r3, float r4)
{
	// create matrix(size) for array (made within parent Matrix class)
	this->createMatrix(16);

	// Set values in matrix (within parent class Matrix.cpp)
	this->matrixArray[0] = r1;
	this->matrixArray[1] = r2;
	this->matrixArray[2] = 0;
	this->matrixArray[3] = 0;
	this->matrixArray[4] = r3;
	this->matrixArray[5] = r4;
	this->matrixArray[6] = 0;
	this->matrixArray[7] = 0;
	this->matrixArray[8] = 0;
	this->matrixArray[9] = 0;
	this->matrixArray[10] = 0;
	this->matrixArray[11] = 0;
	this->matrixArray[12] = 0;
	this->matrixArray[13] = 0;
	this->matrixArray[14] = 0;
	this->matrixArray[15] = 1;
}

// Create 3x3 Matrix
Matrix::Matrix(float r1, float r2, float r3, float r4, float r5, float r6, float r7, float r8, float r9)
{
	// create matrix(size) for array (made within parent Matrix class)
	this->createMatrix(16);

	// Set values in matrix (within parent class Matrix.cpp)
	this->matrixArray[0] = r1;
	this->matrixArray[1] = r2;
	this->matrixArray[2] = r3;
	this->matrixArray[3] = 0;
	this->matrixArray[4] = r4;
	this->matrixArray[5] = r5;
	this->matrixArray[6] = r6;
	this->matrixArray[7] = 0;
	this->matrixArray[8] = r7;
	this->matrixArray[9] = r8;
	this->matrixArray[10] = r9;
	this->matrixArray[11] = 0;
	this->matrixArray[12] = 0;
	this->matrixArray[13] = 0;
	this->matrixArray[14] = 0;
	this->matrixArray[15] = 1;
}

// Create 4x4 Matrix
Matrix::Matrix(float r1, float r2, float r3, float r4, float r5, float r6, float r7, float r8, float r9, float r10, float r11, float r12, float r13, float r14, float r15, float r16)
{
	// create matrix(size) for array (made within parent Matrix class)
	this->createMatrix(16);

	// Set values in matrix (within parent class Matrix.cpp)
	this->matrixArray[0] = r1;
	this->matrixArray[1] = r2;
	this->matrixArray[2] = r3;
	this->matrixArray[3] = r4;
	this->matrixArray[4] = r5;
	this->matrixArray[5] = r6;
	this->matrixArray[6] = r7;
	this->matrixArray[7] = r8;
	this->matrixArray[8] = r9;
	this->matrixArray[9] = r10;
	this->matrixArray[10] = r11;
	this->matrixArray[11] = r12;
	this->matrixArray[12] = r13;
	this->matrixArray[13] = r14;
	this->matrixArray[14] = r15;
	this->matrixArray[15] = r16;
}

// initial matrix creation
bool Matrix::createMatrix(int size)
{
	bool result = false;
	this->matrixArray = nullptr;
	this->matrixArray = new float[size];

	if (this->matrixArray != nullptr)
	{
		result = true;
	}
	else
	{
		// Result already set to false
	}

	return result;

}

void Matrix::print()
{
	cout << this->matrixArray[0] << "\t";
	cout << this->matrixArray[1] << "\t";
	cout << this->matrixArray[2] << "\t";
	cout << this->matrixArray[3] << endl;
	cout << this->matrixArray[4] << "\t";
	cout << this->matrixArray[5] << "\t";
	cout << this->matrixArray[6] << "\t";
	cout << this->matrixArray[7] << endl;
	cout << this->matrixArray[8] << "\t";
	cout << this->matrixArray[9] << "\t";
	cout << this->matrixArray[10] << "\t";
	cout << this->matrixArray[11] << endl;
	cout << this->matrixArray[12] << "\t";
	cout << this->matrixArray[13] << "\t";
	cout << this->matrixArray[14] << "\t";
	cout << this->matrixArray[15] << endl << endl;
}