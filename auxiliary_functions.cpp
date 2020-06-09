#include <iostream>
#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include "auxiliary_functions.h"
#include <math.h>

using namespace std;

Color getColor(float pixelX, float pixelY)
{
	Color pixelColor;
	glReadPixels(pixelX, pixelY, 1, 1, GL_RGB, GL_FLOAT, &pixelColor);

	return pixelColor;
}

float mapValue(float val, float fromMin, float fromMax, float toMin, float toMax)
{
	return (val - fromMin) * (toMax - toMin) / (fromMax - fromMin) * 1.0 + toMin;
}

bool isInFreeSpace(int x, int y)
{
	Color pointColor = getColor(x, y);

	if (pointColor.r == 1.0 && pointColor.g == 0.0 && pointColor.b == 0.0)
	{
		return false;
	}
	return true;
}

bool isPathFree(int stX, int stY, int glX, int glY)
{
	/*float tempX, tempY;

	float angle = atan( abs(glY-stY) / abs(glX-stX) );
	while (((int)tempX != (int)glX) && ((int)tempY != (int)glY))
	{
		if (stX < glX)
		{
			stX++;
			if (stY > glY)
			{
				tempX = stX;
				tempY = stY - tan(angle)*stX;
				if (!isInFreeSpace(tempX, tempY))
				{
					return true;
				}
			}
			else
			{
				tempX = stX;
				tempY = stY + tan(angle)*stX;
				if (!isInFreeSpace(tempX, tempY))
				{
					return true;
				}
			}
		}
		else if (stX > glX)
		{
			stX--;

			if (stY > glY)
			{
				tempX = stX;
				tempY = stY - tan(angle)*stX;
				if (!isInFreeSpace(tempX, tempY))
				{
					return true;
				}
			}
			else
			{
				tempX = stX;
				tempY = stY + tan(angle)*stX;
				if (!isInFreeSpace(tempX, tempY))
				{
					return true;
				}
			}
		}
	}*/

	return false;
}