#pragma once

class Calculations
{
private:
	const float PI = 3.141592f;

public:
	Calculations();
	~Calculations();

	void init();

	Vector *vectorResult;
	Matrix *translation;
	Matrix *scale;
	Matrix *rotate;
	Matrix *result;
	Vector *vector;

	int convert;
	float sinLUT[1024];
	float cosLUT[1024];

	void multiplyMatrixByMatrix(Matrix *, Matrix *);
	void multiply4By4byVector(Matrix *, Vector *);

	void translate(float, float, float, Vector *);

	void rotateX(float, Vector *);
	void rotateY(float, Vector *);
	void rotateZ(float, Vector *);

	void scaleUniform(float, Vector *);
	void scaleNonUniform(float, float, float, float, Vector *);

	float degreesToRadians(float);
	float radiansToDegrees(float);

	float dotProduct2D(Vector *, Vector *);

	void createSinCosLUT();
};