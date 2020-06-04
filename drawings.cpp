#include <iostream>
#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <math.h>
#include "drawings.h"

using namespace std;

void drawCircle(float circleX, float circleY, float r, float g, float b)
{
	float theta = 0;
	glColor3f(r, g, b);

	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		theta = i * PI / 180.0;
		glVertex2f(circleX + R * cos(theta), circleY + R * sin(theta));
	}

	glEnd();
}