#include "GLFW\glfw3.h"

extern GLFWwindow* w1;

void createWindow()
{
	glfwInit();

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DECORATED, false);
	glfwWindowHint(GLFW_RESIZABLE, false);

	w1 = glfwCreateWindow(1000, 600, "will", 0, 0);

	GLFWvidmode *mode;
	mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(w1, mode->width / 2 - 1000 / 2, mode->height / 2 - 600 / 2);

	glfwMakeContextCurrent(w1);
}