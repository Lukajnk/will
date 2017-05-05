#include <iostream>
#include <GLFW\glfw3.h>

extern GLFWwindow *w1;



void setup() 
{
	glfwInit();

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//glfwWindowHint(GLFW_DECORATED, false);

	GLFWvidmode *mode;
	mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());

	int w1width = 800;
	int w1height = 600;

	w1 = glfwCreateWindow(w1width, w1height, "will", NULL, NULL);

	glfwSetWindowPos(w1, mode->width / 2 - w1width / 2, mode->height / 2 - w1height / 2);

	glfwMakeContextCurrent(w1);
	glfwSwapInterval(1);

	std::cout << "s ";
}