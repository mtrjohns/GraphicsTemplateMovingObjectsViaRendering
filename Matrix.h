#pragma once

class Matrix
{
public:
	// array to store matrix values for object
	float* matrixArray;

	// Default Matrix constructor
	Matrix();
	// 3x1 Matrix Constructor
	Matrix(float, float, float);
	// 2x2 Matrix Constructor
	Matrix(float, float, float, float);
	// 3x3 Matrix Constructor
	Matrix(float, float, float, float, float, float, float, float, float);
	// 4x4 Matrix Constructor
	Matrix(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);

	// Matrix Destructor
	~Matrix();

	void identityMatrix();
	// initial matrix creator
	bool createMatrix(int);

	void print();
};