#pragma once
class FlyManager
{
public:
	int size;
	int leftFlyIndex;

	Vector *flyArray;
	Vector *direction;

	FlyManager(int);
	bool createFlyArray(int);
	void setFlyVectors();
	void moveDirection();
	int leftFly();
	~FlyManager();
};