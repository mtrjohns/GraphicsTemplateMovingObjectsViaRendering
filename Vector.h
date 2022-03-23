#pragma once

class Vector
{
public:
	float x, y, z, w;

	Vector();
	Vector(float, float, float, float);

	~Vector();

	void print();
};