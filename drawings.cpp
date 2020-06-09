#include <iostream>
#include <vector>
#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <math.h>
#include "drawings.h"
#include "window_parameters.h"

using namespace std;

vector < vector <float> > walls;

void initDrawingParameters()
{
	
}

void drawWalls()
{
	glPointSize(10);
	for (int i = 0; i < walls.size(); i++)
	{
		glBegin(GL_POINTS);
		glColor3f(0, 1, 1);
		glVertex2f(walls[i][0], walls[i][1]);
		glEnd();
	}
}

void drawStartAndEndPositions(int posX, int posY, float r, float g, float b)
{
	glPointSize(15);

	glBegin(GL_POINTS);

	glColor3f(r, g, b);
	glVertex2f(posX, posY);

	glEnd();
}