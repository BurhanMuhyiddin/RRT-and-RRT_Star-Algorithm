#include <iostream>
#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include "drawings.h"

using namespace std;

#define FPS		10		// Frame per second
#define W_W		500		// Window width
#define W_H		500		// Window height
#define X_MAX	40.0	// Max value of X
#define Y_MAX	40.0	// Max value of Y

// Definitions of callback functions
void display_callback();
void reshape_callback(int, int);
void keyboard_callback(unsigned char, int, int);
void mouse_callback(int, int, int, int);
void timer_callback(int);
// End of definitions of callback functions

float mapValue(float, float, float, float, float);

// Definition of user defined variables
bool is_set_goal = false;
bool is_set_init = false;
float goalX = -999.0, goalY = -999.0;
float startX = -999.0, startY = -999;
// End of definition of user defined variables

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(W_W, W_H);
	glutCreateWindow("RRT_RRT*");

	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutKeyboardFunc(keyboard_callback);
	glutMouseFunc(mouse_callback);
	glutTimerFunc(0, timer_callback, 0);

	init();

	glutMainLoop();
}

void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	drawCircle(startX, startY, 1.0, 1.0, 0.0);	// Draw start position
	drawCircle(goalX, goalY, 0.0, 1.0, 0.0);	// Draw goal position

	glutSwapBuffers();
}

void reshape_callback(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, X_MAX, Y_MAX, 0.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard_callback(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'i':
		is_set_goal = false;
		is_set_init = true;
		break;
	case 'g':
		is_set_init = false;
		is_set_goal = true;
		break;
	}
}

void mouse_callback(int button, int state, int mouseX, int mouseY)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (is_set_goal)
		{
			goalX = mapValue(mouseX, 0, W_W, 0, X_MAX);
			goalY = mapValue(mouseY, 0, W_H, 0, Y_MAX);
		}
		else if (is_set_init)
		{
			startX = mapValue(mouseX, 0, W_W, 0, X_MAX);
			startY = mapValue(mouseY, 0, W_H, 0, Y_MAX);
		}
	}
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

float mapValue(float val, float fromMin, float fromMax, float toMin, float toMax)
{
	return (val - fromMin) * (toMax - toMin) / (fromMax - fromMin) * 1.0 + toMin;
}