#include <iostream>
#include "GLFW\glfw3.h"

void render()
{
	std::cout << "r ";
	glColor3f(0.4, 0.25, 0.3);
	glBegin(GL_TRIANGLES);

	glVertex2i(0, 0);
	glVertex2i(1000, 0);
	glVertex2i(0, 600);

	glVertex2i(1000, 0);
	glVertex2i(1000, 600);
	glVertex2i(0, 600);
	glEnd();
}