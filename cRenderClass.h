

class cRenderClass
{
public:

	cRenderClass(const int, const int);
	~cRenderClass();

	void create(int argc, _TCHAR* argv[]);
	void loop();

	void clear();

	void render();
	void setColour(float, float, float);
	void setPointSize(int);
	void drawPixel(int, int);

	// Work out line equation
	float lineEquation(float, float, float, float);
	float lineSlope(float, float, float, float);

	// Line Draw functions
	void lineDirectScan(float, float, float, float);
	void lineDDA(float, float, float, float);
	void lineBresenhams(float, float, float, float);

	// Circle Draw
	void lineCircle(float, float, float);

	// Jarvis March Convex Hull
	FlyManager* hull = nullptr;
	int orientation(Vector p, Vector q, Vector r);
	void jarvisMarchHull(FlyManager *);

private:

	int		 m_sw, m_sh;
	int		 m_point_size;
	float	*m_buffer;
	sRGB	 m_colour;

	// initialise maths variables
	float m = 0.0f;
	float b = 0.0f;
	float step = 0.0f;
	float y = 0.0f;
};