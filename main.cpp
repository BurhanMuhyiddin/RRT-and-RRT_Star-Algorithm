#include <iostream>
#include <vector>
#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include "drawings.h"
#include "auxiliary_functions.h"
#include "window_parameters.h"

using namespace std;

// Definitions of callback functions
void display_callback();
void reshape_callback(int, int);
void keyboard_callback(unsigned char, int, int);
void mouse_callback(int, int, int, int);
void timer_callback(int);
void motion_callback(int x, int y);
// End of definitions of callback functions

// Definition of user defined variables
bool is_set_goal = false;
bool is_set_init = false;
bool is_set_obstacle = false;
bool is_mouse_clicked = false;
float goalX = -999.0, goalY = -999.0;
float startX = -999.0, startY = -999;
// End of definition of user defined variables

extern vector < vector <float> > walls;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	//initDrawingParameters();
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
	glutMotionFunc(motion_callback);
	glutTimerFunc(0, timer_callback, 0);

	init();

	glutMainLoop();
}

void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	drawWalls();
	drawStartAndEndPositions(startX, startY, 1.0, 1.0, 0.0);	// Draw start position
	drawStartAndEndPositions(goalX, goalY, 0.0, 1.0, 0.0);	    // Draw goal position

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
	case 'i':	// Start draw mode
		is_set_goal = false;
		is_set_obstacle = false;
		is_mouse_clicked = false;
		is_set_init = true;
		break;
	case 'g':	// Goal draw mode
		is_set_init = false;
		is_set_obstacle = false;
		is_mouse_clicked = false;
		is_set_goal = true;
		break;
	case 'o':	// Obstacle draw mode
		is_set_init = false;
		is_set_goal = false;
		is_set_obstacle = true;
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
		else if (is_set_obstacle)
		{
			is_mouse_clicked = true;
		}
	}
}

void motion_callback(int x, int y)
{
	if (is_mouse_clicked)
	{
		vector <float> tmp;
		tmp.push_back(x);
		tmp.push_back(y);
		walls.push_back(tmp);
	}
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}