#include <iostream>
#include "GLFW\glfw3.h"

extern GLFWwindow* w1;

void render()
{
	std::cout << "r ";
	glColor3f(0.0, 0.4, 0.4);
	glBegin(GL_TRIANGLES);

	glVertex2i(10, 10);
	glVertex2i(990, 10);
	glVertex2i(10, 565);

	glVertex2i(990, 10);
	glVertex2i(990, 565);
	glVertex2i(10, 565);
	glEnd();

	glColor3f(0.3, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	glVertex2i(950, 575);
	glVertex2i(990, 575);
	glVertex2i(950, 590);

	glVertex2i(990, 575);
	glVertex2i(990, 590);
	glVertex2i(950, 590);
	glEnd();
}