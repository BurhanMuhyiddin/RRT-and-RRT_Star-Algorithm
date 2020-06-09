#ifndef AUXILIARY_FUNCTIONS_H_INCLUDED
#define AUXILIARY_FUNCTIONS_H_INCLUDED

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

Color getColor(float pixelX, float pixelY);
float mapValue(float, float, float, float, float);
bool isInFreeSpace(int, int);
bool isPathFree(int, int, int, int);

#endif // !AUXILIARY_FUNCTIONS_H_INCLUDED
