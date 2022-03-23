#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

// create fly objects here
FlyManager flies(10);

// Must pass in array size
FlyManager::FlyManager(int size)
{
	this->size = size;
	this->createFlyArray(size);
}

// Create Fly Array
bool FlyManager::createFlyArray(int size)
{
	bool result = false;

	this->flyArray = nullptr;
	this->flyArray = new Vector[this->size];
	this->direction = nullptr;
	this->direction = new Vector[this->size];

	if (this->flyArray != nullptr && this->direction != nullptr)
	{
		result = true;
	}
	else
	{
		// Result already set to false
	}

	return result;
}

void FlyManager::setFlyVectors()
{
	// start points within the window
	int spawnMaxX = SCREEN_WIDTH - 20; // max X offset
	int spawnMinX = SCREEN_WIDTH - SCREEN_WIDTH + 20; // Min X offset
	int spawnMaxY = SCREEN_HEIGHT - 20; // max Y offset
	int spawnMinY = SCREEN_HEIGHT - SCREEN_HEIGHT + 20; // Min Y offset

	for (int i = 0; i < this->size; i++)
		flies.flyArray[i] = Vector(rand() % spawnMaxX + spawnMinX, rand() % spawnMaxY + spawnMinY, 1.0f, 1.0f);
}

// random fly velocity
void FlyManager::moveDirection()
{
	srand(time(NULL));

	for (int i = 0; i < this->size; i++)
	{
		flies.direction[i] = Vector(rand() % 3 + 1, rand() % 3 + 1, 1.0f, 1.0f);
	}
}


// attempted to control left fly outside of hull. 
// starts ok but currently causing unknown bug that multiplies files
int FlyManager::leftFly()
{

	for (int i = 1; i < size - 1; i++)
	{
		if (flyArray[i].x < flyArray[leftFlyIndex].x)
			leftFlyIndex = i;
		//cout << "Size = " << leftFlyIndex << endl;
	}
	//cout << "Left fly index = " << leftFlyIndex << endl;
	return leftFlyIndex;
}

FlyManager::~FlyManager()
{
	delete[] this->flyArray;
	delete[] this->direction;
}
