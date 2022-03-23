#include "stdafx.h"
 Vector p0;
 Vector p1;
 Vector p2;
 Vector p3;
 Vector centre;
Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Vector::Vector(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector::~Vector()
{

}

void Vector::print()
{
	cout << this->x << endl << this->y << endl << this->z << endl << this->w << endl << endl;
}