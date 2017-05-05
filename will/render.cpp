#include <iostream>
#include <chrono>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

extern GLFWwindow* w1;

extern bool loop;
extern long ticklength;
long long tp2;

void render()
{
	while (!glfwWindowShouldClose(w1) && loop) 
	{
		tp2 = std::chrono::steady_clock::now().time_since_epoch().count();

		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(w1);
		glfwPollEvents();

		std::cout << "r ";

		while (std::chrono::steady_clock::now().time_since_epoch().count() - tp2 <= ticklength);
	}

	glfwDestroyWindow(w1);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}