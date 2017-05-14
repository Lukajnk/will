#include "GLFW\glfw3.h"

extern GLFWwindow* w1;



void createWindow()
{
	int window_width = 1000;
	int window_height = 600;

	glfwInit();

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DECORATED, false);
	glfwWindowHint(GLFW_RESIZABLE, false);

	w1 = glfwCreateWindow(window_width, window_height, "will", 0, 0);

	GLFWvidmode *mode;
	mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(w1, mode->width / 2 - window_width / 2, mode->height / 2 - window_height / 2);

	glfwMakeContextCurrent(w1);

	glMatrixMode(GL_PROJECTION);
	glOrtho(0, window_width, 0, window_height, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}