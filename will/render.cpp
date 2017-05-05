#include <iostream>
#include <chrono>
#include <GLFW\glfw3.h>

extern GLFWwindow* w1;

extern bool loop;
extern long ticklength;
long long tp2;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		loop = false;
}

void render()
{
	glfwSetKeyCallback(w1, key_callback);

	while (loop) 
	{
		tp2 = std::chrono::steady_clock::now().time_since_epoch().count();

		//glClear(GL_COLOR_BUFFER_BIT);

		std::cout << "r ";

		glfwSwapBuffers(w1);
		glfwPollEvents();

		while (std::chrono::steady_clock::now().time_since_epoch().count() - tp2 <= ticklength);
	}

	glfwDestroyWindow(w1);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}