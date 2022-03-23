// GraphicsTemplate.cpp
// 
//////////////////////////////////////////////////////////////////////////////////////////
// includes 
//////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////////////////////
// externals 
//////////////////////////////////////////////////////////////////////////////////////////
extern cRenderClass graphics;
extern Calculations calc;
extern FlyManager flies;
extern Vector p0;
extern Vector p1;
extern Vector p2;
extern Vector p3;
extern Vector centre;

//////////////////////////////////////////////////////////////////////////////////////////
// renderScene() - render the scene
//////////////////////////////////////////////////////////////////////////////////////////
void renderScene()
{
	// set a colour
	graphics.setColour( 1,0,0 );
	
	// set pixel size..
	graphics.setPointSize(5);
	//graphics.drawLine(&p0, &p1);


	// draw to an off screen buffer
	//graphics.drawPixel(p0.x, p0.y);
	//graphics.drawPixel(p1.x, p1.y);
	//graphics.drawPixel(p2.x, p2.y);
	//graphics.drawPixel(p3.x, p3.y);

	// render the scene
	graphics.render();
}

//////////////////////////////////////////////////////////////////////////////////////////
// update() - update function
//////////////////////////////////////////////////////////////////////////////////////////
void update()
{
	// add any update code here...


	
	/*********************************************************************
	* DRAW FLY CODE
	*********************************************************************/

	/*for (int i = 0; i < flies.size; i++)
	{
		// draw flies as pixels
		graphics.drawPixel(flies.flyArray[i].x, flies.flyArray[i].y);


		// Translate flies position
		calc.translate(flies.direction[i].x, flies.direction[i].y, 0, &flies.flyArray[i]);

		// change direction with reflection law if sides of screen hit
		if (flies.flyArray[i].x < (SCREEN_WIDTH - SCREEN_WIDTH + 2) ^ flies.flyArray[i].x > (SCREEN_WIDTH - 2))
		{
			flies.direction[i].x = -flies.direction[i].x;
		}


		// change direction with reflection law if top or bottom of screen hit
		if (flies.flyArray[i].y < (SCREEN_HEIGHT - SCREEN_HEIGHT + 2) || flies.flyArray[i].y > (SCREEN_HEIGHT - 2))
		{
			flies.direction[i].y = -flies.direction[i].y;
		}

		// uncomment to show changes in fly direction
		//cout << "flies direction[" << i << "] = (" << flies.direction[i].x << ", " << flies.direction[i].y << ")" << endl;


		// uncomment to show changes in fly location
		//cout << "flies location[" << i << "] = (" << flies.flyArray[i].x << ", " << flies.flyArray[i].y << ")" << endl;

		//calc.rotateX(0.5, &flies.flyArray[i]);
		//calc.rotateY(0.5, &flies.flyArray[i]);
		//calc.rotateZ(0.5, &flies.flyArray[i]);
		//calc.scaleNonUniform(0.01f, 1.0f, 1.0f, 1.0f, &flies.flyArray[i]);

	}

	// encapsulate all flies inside a convex hull
	graphics.jarvisMarchHull(&flies);

	*/


	/*********************************************************************
	* OTHER MATH LIBRARY FEATURES // vectors with approiate names would need to be created
	*********************************************************************/
	
	
	//graphics.lineCircle(100, p0.x, p0.y);

	//graphics.lineEquation(p0.x, p0.y, p1.x, p1.y);

	//graphics.directScan(p0.x, p0.y, p1.x, p1.y);
	//graphics.directScan(p1.x, p1.y, p2.x, p2.y);
	//graphics.directScan(p3.x, p3.y, p2.x, p2.y);
	//graphics.directScan(p3.x, p3.y, p0.x, p0.y);

	//graphics.lineDDA(p0.x, p0.y, p1.x, p1.y);
	//graphics.lineDDA(p1.x, p1.y, p2.x, p2.y);
	//graphics.lineDDA(p3.x, p3.y, p2.x, p2.y);
	//graphics.lineDDA(p0.x, p0.y, p3.x, p3.y);

	//graphics.lineBresenhams(p2.x, p2.y, p0.x, p0.y);
	//graphics.lineBresenhams(p3.x, p3.y, p2.x, p2.y);
	//graphics.lineBresenhams(p2.x, p2.y, p1.x, p1.y);
	//graphics.lineBresenhams(p3.x, p3.y, p1.x, p1.y);
	//graphics.lineBresenhams(p3.x, p3.y, p0.x, p0.y);
	


	/*/ Rotation
	p0.x -= centre.x;
	p0.y -= centre.y;
	p0.z -= centre.z;
	p0.w -= centre.w;
	p1.x -= centre.x;
	p1.y -= centre.y;
	p1.z -= centre.z;
	p1.w -= centre.w;

	p2.x -= centre.x;
	p2.y -= centre.y;
	p2.z = centre.z;
	p2.w -= centre.w;
	p3.x -= centre.x;
	p3.y -= centre.y;
	p3.z -= centre.z;
	p3.w -= centre.w;
	
	//calc.rotateZ(3, &p0);
	//calc.rotateZ(3, &p1);
	//calc.rotateZ(3, &p2);
	//calc.rotateZ(3, &p3);

	//calc.rotateY(1, &p0);
	//calc.rotateY(1, &p1);
	//calc.rotateY(1, &p2);
	//calc.rotateY(1, &p3);

	calc.rotateX(5, &p0);
	calc.rotateX(5, &p1);
	calc.rotateX(5, &p2);
	calc.rotateX(5, &p3);
	calc.rotateX(5, &centre);
	
	p0.x += centre.x;
	p0.y += centre.y;
	p0.z += centre.z;
	p0.w += centre.w;
	p1.x += centre.x;
	p1.y += centre.y;
	p1.z += centre.z;
	p1.w += centre.w;
	p2.x += centre.x;
	p2.y += centre.y;
	p2.z += centre.z;
	p2.w += centre.w;
	p3.x += centre.x;
	p3.y += centre.y;
	p3.z += centre.z;
	p3.w += centre.w;
	*/

	/*
	// Transform
	calc.translate(0, 1, 0, &p0);
	calc.translate(1, 0, 0, &p1);
	calc.translate(1, 0, 0, &p2);
	calc.translate(1, 0, 0, &p3);
	*/



	/*
	calc.scaleNonUniform(0.999f, 1, 1, 1, &p0);
	calc.scaleNonUniform(1.0f, 1, 1, 1, &p1);
	calc.scaleNonUniform(1.0f, 1, 1, 1, &p2);
	calc.scaleNonUniform(1.0f, 1, 1, 1, &p3);
	*/



	
	calc.scaleUniform(0.999f, &p0);
	calc.scaleUniform(0.999f, &p1);
	calc.scaleUniform(0.999f, &p2);
	calc.scaleUniform(0.999f, &p3);
	//calc.scaleUniform(0.999f, &centre);
	



	/*
	//p0.print();
	//p1.print();
	//p2.print();
	//p3.print();
	*/

	graphics.drawPixel(p0.x, p0.y);
	graphics.drawPixel(p1.x, p1.y);
	graphics.drawPixel(p2.x, p2.y);
	graphics.drawPixel(p3.x, p3.y);


	// always re-render the scene..
	renderScene();
}

//////////////////////////////////////////////////////////////////////////////////////////
// _tmain() - program entry point
//////////////////////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{	
	// init glut stuff..
	graphics.create(argc, argv);

	// good place for one-off initialisations and objects creation..

	p0.x = 200.0f;
	p0.y = 200.0f;
	p0.z = 1.0f;
	p0.w = 1.0f;

	p1.x = 400.0f;
	p1.y = 200.0f;
	p1.z = 1.0f;
	p1.w = 1.0f;

	p2.x = 400.0f;
	p2.y = 400.0f;
	p2.z = 1.0f;
	p2.w = 1.0f;

	p3.x = 200.0f;
	p3.y = 400.0f;
	p3.z = 1.0f;
	p3.w = 1.0f;

	centre.x = 300.0f;
	centre.y = 300.0f;
	centre.z = 1.0f;
	centre.w = 1.0f;


	// randomly generate fly positions
	flies.setFlyVectors();

	// randomly generate fly direction (velocity)
	flies.moveDirection();

	// enter game loop..
	graphics.loop();

	return 0;
}


/*
interpolation - fill a triangle with color (rasterization)
*/