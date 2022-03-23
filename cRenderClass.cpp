//////////////////////////////////////////////////////////////////////////////////////////
// cRenderClass.cpp
//////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////////////////////
// Declarations 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass graphics( SCREEN_WIDTH, SCREEN_HEIGHT );
extern Calculations calc;

//////////////////////////////////////////////////////////////////////////////////////////
// cRenderClass() - constructor 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass::cRenderClass(const int w, const int h)
{
	m_sw = w;
	m_sh = h;

	int total_count = w*h*3;

	m_buffer = new float[total_count];

	for( int i=0; i<total_count; i++ )
	{
		m_buffer[i] = 0;
	}

	m_point_size = 1;
}

//////////////////////////////////////////////////////////////////////////////////////////
// cRenderClass() - destructor 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass::~cRenderClass()
{

}

//////////////////////////////////////////////////////////////////////////////////////////
// loop() - enters game loop
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::loop()
{
	glutMainLoop();
}

//////////////////////////////////////////////////////////////////////////////////////////
// initialize glut stuff
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::create(int argc, _TCHAR* argv[])
{
	// initialise the glut library
	glutInit(&argc, argv);

	// set up the initial display mode
	// need both double buffering and z-buffering
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// set the initial window position
	glutInitWindowPosition(100, 100);

	// set the initial window size
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	// create and name the window
	glutCreateWindow("Wow!");

	// reshape callback for current window
	glutReshapeFunc(winReshapeFunc);

	// set display callback for current window
	glutDisplayFunc(renderScene);	

	// set up the global idle callback
	glutIdleFunc(update);
}

//////////////////////////////////////////////////////////////////////////////////////////
// clear() - clears out the render buffer 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::clear()
{
	memset( m_buffer, 0, sizeof(float)*m_sw*m_sh*3 );
}

//////////////////////////////////////////////////////////////////////////////////////////
// setPointSize() - set the pixel size 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::setPointSize(int size)
{
	m_point_size = size;
}

//////////////////////////////////////////////////////////////////////////////////////////
// drawPixel() -  
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::drawPixel(int x, int y)
{
	int start, end;

	start = -(m_point_size/2);
	end	= (int)((m_point_size/2.0f) + 0.5);

	for( int i=start; i<end; i++ )
	{
		for( int j=start; j<end; j++ )
		{
			if( (x+j < 0) || (x+j >= m_sw) )
				continue;

			if( (y+i < 0) || (y+i >= m_sh) )
				continue;

			m_buffer[(((y+i)*m_sw+(x+j))*3) + 0] = m_colour.r;
			m_buffer[(((y+i)*m_sw+(x+j))*3) + 1] = m_colour.g;
			m_buffer[(((y+i)*m_sw+(x+j))*3) + 2] = m_colour.b;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// Line Equation calculation
//////////////////////////////////////////////////////////////////////////////////////////
float cRenderClass::lineEquation(float p0X, float p0Y, float p1X, float p1Y)
{
	// calculate slope
	m = (p1Y - p0Y) / (p1X - p0X);

	// calculate incept point of Y
	b = p0Y - m * p0X;

	//cout << "slope = " << m << ", intercept = " << b << endl;

	// return equation of a straight line (y = mx + b)
	return (m*p0X+b);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Line slope calculation
//////////////////////////////////////////////////////////////////////////////////////////
float cRenderClass::lineSlope(float p0X, float p0Y, float p1X, float p1Y)
{
	// calculate slope
	m = (p1Y - p0Y) /(p1X - p0X);

	return m;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Direct scan line draw algorithm function - horizontal lines only
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::lineDirectScan(float p0X, float p0Y, float p1X, float p1Y)
{
	if (p0X <= p1X)
	{
		step = p0X;

		while (step <= p1X)
		{
			//cout << "Step = " << step << ", P0X = " << p0X << endl;
			y = lineEquation(step, p0Y, p1X, p1Y);
			//cout << "Y = " << y << endl;
			drawPixel(step, y);
			step++;
		}
		
	}
	else
	{
		step = p1X;

		while (step < p0X)
		{
			//cout << "Step = " << step << ", P1X = " << p1X << endl;
			y = lineEquation(step, p0Y, p1X, p1Y);
			//cout << "pixel position (" << step << ", " << y << ")" << endl;
			drawPixel(step, y);
			step++;
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// DDA Line drawing algorithm function (currently left to right only on points and positive slopes)
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::lineDDA(float p0X, float p0Y, float p1X, float p1Y)
{
	float step = 1;

	// Calculate line equation ( m = slope, b = Y intercept)
	lineEquation(p0X, p0Y, p1X, p1Y);

	// Calculate deltas
	float dy = p1Y - p0Y;
	float dx = p1X - p0X;

	dy = m * dx;
	dx = dy / m;

	float x = p0X;
	float y = p0Y;

	// if slope (m) is less than or equal to 1
	if (m <= 1.0f)
	{
		while (x < p1X)
		{
			drawPixel(x, y);
			y = y + m;
			x++;
		}
	}
	// If slope is greater than 1 ( use y increment value instead of x)
	else
	{
		while (y < p1Y)
		{
			drawPixel(x, y);
			x = x + (1 / m);
			y++;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// Bresenham's line drawing algorithm
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::lineBresenhams(float p0X, float p0Y, float p1X, float p1Y)
{

	int x, y, xEnd, yEnd;
	int i = 0;

	// Calculate deltas
	int dx = p1X - p0X; // length of line on X
	int dy = p1Y - p0Y; // length of line on Y

	// absolute values to check length even with negative length
	int dxAbs; // = fabs(dx);
	int dyAbs; // = fabs(dy);

	// if less than zero, convert to absolute (positive) value to compare length
	if (dx < 0)
	{
		dxAbs = (dx)-(dx + dx);
		//cout << "dxAbs = " << dxAbs << endl;
	}
	else
	{
		dxAbs = dx;
		//cout << "dxAbs = " << dxAbs << endl;
	}

	if (dy < 0)
	{
		dyAbs = (dy)-(dy + dy);
		//cout << "dyAbs = " << dyAbs << endl;
	}
	else
	{
		dyAbs = dy;
		//cout << "dyAbs = " << dyAbs << endl;
	}

	int dy2Minusdx2 = 2 * (dyAbs - dxAbs);
	int dx2Minusdy2 = 2 * (dxAbs - dyAbs);

	// starting value for decision parameter (error value check on line)
	int parameterX = 2 * dyAbs - dxAbs; // for values with x axis being used as decision parameter
	int parameterY = 2 * dxAbs - dyAbs; // for values with y axis being used as decision parameter

	// if y step is smaller or equal to x step
	// then step along x
	if (dyAbs <= dxAbs)
	{
		// if x step is negative
		if (dx < 0)
		{
			x = p1X;
			y = p1Y;
			// xEnd will be left of starting pixel
			xEnd = p0X;
		}
		// else x step is postive
		else
		{
			x = p0X;
			y = p0Y;
			// xEnd will be right of starting pixel
			xEnd = p1X;
		}
		// draw first pixel
		drawPixel(x, y);

		//cout << "PX = " << parameterX << endl;
		//cout << "( " << x << ", " << y << ")" << endl;

		// step through from x to xEnd point
		for (i = 0; x < xEnd; i++)
		{
			x++;
				// if x decision parameter is less than zero
				if (parameterX < 0)
				{

					//cout << "parameterX < 0 --" << endl;
					// decision parameter now equals previous parameterX + deltaY*2
					parameterX += 2 * dyAbs;
				}
				// if  dx and dy are anything other than zero
				else
				{
					if ((dx<0 && dy<0) || (dx>0 && dy>0))
					{
						//cout << "dx dy not equal zero --" << endl;
						// next plot is (x, y + 1)
						y++;
					}
					else
					{
						//cout << "parameterX >  0 or higher --" << endl;
						// next plot is (x, y - 1)
						y--;
					}
					// decision parameter now equals previous parameterX + deltaY*2 - DeltaX*2
					parameterX += dy2Minusdx2;
				}
				//cout << "PX after = " << parameterX << endl;
				//cout << "( " << x << ", " << y << ")" << endl;
				drawPixel(x, y);
		}
	}
	// else x step is larger than y step
	// same as above but for decision parameter to be performed on Y axis
	else
	{
		// check if y step is positive or negative and set end point
		if (dy < 0)
		{
			x = p1X;
			y = p1Y;
			yEnd = p0Y;
		}
		else
		{
			x = p0X;
			y = p0Y;
			yEnd = p1Y;
		}

		// draw first pixel
		drawPixel(x, y);

		// while y is not at right hand point of line
		for (i = 0; y < yEnd; i++)
		{
			//cout << "else y++ " << endl;
			// increment y each step
			y++;

			// if y decision parameter is less than or equal to zero
			if (parameterY <= 0)
			{
				//cout << "parameterY <= 0 --" << endl;

				// decision parameter now equals previous parameterY + deltaX*2
				parameterY += 2 * dxAbs;
			}
			// if  dx and dy are anything other than zero
			else 
			{	// else / if indentation matters due to parameter being set 
				// - this took a while to notice...
				if ((dx<0 && dy<0) || (dx>0 && dy>0))
				{

					//cout << "dx dy not equal zero -ELSE-" << endl;

					// next plot is (x + 1, y)
					x++;
				}
				else
				{
					//cout << "parameterY >  0 or higher --" << endl;

					// next plot is (x - 1, y)
					x--;
				}
				// decision parameter now equals previous parameterY + deltaX*2 - DeltaY*2
				parameterY += dx2Minusdy2;
			}
			//cout << "else ( " << x << ", " << y << ")" << endl;
			// draw decided pixel
			drawPixel(x, y);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// Circle Drawing - Optimized for reflection
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::lineCircle(float radius, float x, float y)
{
	float xNew;
	float yNew;
	int i;

	for (i = 0; i < 360; i++)
	{ 

		xNew = x + (radius * calc.cosLUT[i]);
		yNew = y + (radius * calc.sinLUT[i]);
		drawPixel(xNew, yNew); // octant 0 ( 0 to 45 degrees) ( quadrant 0 with 360 loops)
		//drawPixel(yNew, xNew); // octant 1 ( 45 to 90 degrees)
		
		xNew = x - (radius * calc.cosLUT[i]);
		yNew = y + (radius * calc.sinLUT[i]);
		drawPixel(xNew, yNew); // octant 3 ( 135 to 180 degrees) ( quadrant 1 with 360 loops)
		//drawPixel(yNew, xNew); // octant 7 ( 270 to 315 degrees)
		
		xNew = x + (radius * calc.cosLUT[i]);
		yNew = y - (radius * calc.sinLUT[i]);
		drawPixel(xNew, yNew); // octant 8 ( 315 to 360 degrees) ( quadrant 4 with 360 loops)
		//drawPixel(yNew, xNew); // octant 2 ( 90 to 135 degrees)
		
		xNew = x - (radius * calc.cosLUT[i]);
		yNew = y - (radius * calc.sinLUT[i]);
		drawPixel(xNew, yNew); // octant 4 ( 180 to 225 degrees) ( quadrant 3 with 360 loops)
		//drawPixel(yNew, xNew); // octant 5 ( 225 to 270 degrees)
		
		/////////////////////////
		// Commented draws was an attempt to get 180 loop working
		// caused issues on translation of a circle
		////////////////////////

		//cout << "( " << xNew << ", " << yNew << ")" << endl;
	}
}

///// Reference [1]
int cRenderClass::orientation(Vector p, Vector q, Vector r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0)
	{
		return 0;  // colinear
	}

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

///// Reference [1], [2], [3], [4]
// Prints convex hull of a set of n points.
void cRenderClass::jarvisMarchHull(FlyManager* flies)
{

	int size = flies->size;
	int leftFly = 0;
	int p = 0;
	int q = 0;
	// count vector coords added to hull array
	int count = 0;

	// Initialize Result

	if (hull == nullptr)
	{
		//cout << "making hull" << endl;
		hull = new FlyManager(size);
	}

	// Calculate left most point
	for (int i = 1; i < size; i++)
	{
		if (flies->flyArray[i].x < flies->flyArray[leftFly].x)
		{
			leftFly = i;
		}
	}

	// set p as left fly index
	p = leftFly;

	// loop vector coords
	do
	{
		// Add vector coord to hull array
		hull->flyArray[count] = flies->flyArray[p];

		// increment flies in hull count
		count++;

		q = (p + 1);
		
		for (int i = 0; i < size; i++)
		{
			// If i is more counterclockwise than current q, then
			// update q
			if (orientation(flies->flyArray[p], flies->flyArray[i], flies->flyArray[q]) == 2)
				q = i;
		} 

		// Set p as q for next iteration
		// add to hull
		p = q;

	} while (p != leftFly);  // While we don't come to first point
	
	// draw convex hull
	for (int i = 0; i < count; i++)
	{
		// if end of array reached, connect first(most left point) to current
		if (i + 1 >= count)
		{
			lineBresenhams(hull->flyArray[i].x, hull->flyArray[i].y, hull->flyArray[0].x, hull->flyArray[0].y);
		}
		else
		{
			lineBresenhams(hull->flyArray[i].x, hull->flyArray[i].y, hull->flyArray[i + 1].x, hull->flyArray[i + 1].y);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// render() - renders this buffer to screen 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::render()
{
	// clear the back buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawPixels( m_sw, m_sh, GL_RGB, GL_FLOAT, m_buffer );

	// swap the buffers of the current window
	glutSwapBuffers();

	// clear out the buffer
	clear();
}

//////////////////////////////////////////////////////////////////////////////////////////
// setColour() - sets the current colour 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::setColour(float r, float g, float b)
{
	m_colour.r = r;
	m_colour.g = g;
	m_colour.b = b;
}

//////////////////////////////////////////////////////////////////////////////////////////
// winReshapeFunc() - gets called initially and whenever the window get resized
// resizing has been locked
//////////////////////////////////////////////////////////////////////////////////////////
void winReshapeFunc(GLint w, GLint h)
{
	// specify current matrix
	glMatrixMode(GL_PROJECTION);

	// load an identity matrix
	glLoadIdentity();	

	// create a projection matrix... i.e. 2D projection onto xy plane
	glOrtho( -SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// set up the viewport
	glViewport
	(
		0,				// lower left x position
		0,				// lower left y position
		(GLsizei) SCREEN_WIDTH,	// viewport width
		(GLsizei) SCREEN_HEIGHT	// viewport height
	);
}
