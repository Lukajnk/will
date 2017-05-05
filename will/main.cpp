#include <chrono>
#include <thread>
#include <iostream>
#include "GLFW\glfw3.h"

bool loop = true;
long ticklength = 1000000000 / 30;
long long loopstart, tpr;
GLFWwindow *w1;

void setup();
void update();
void render();

int main() 
{
	loopstart = std::chrono::steady_clock::now().time_since_epoch().count();

	setup();

	std::thread thread_update(update);

	while (loop)
	{
		tpr = std::chrono::steady_clock::now().time_since_epoch().count();

		glClearColor(0.0f, 0.42f, 0.42f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		render();

		glfwSwapBuffers(w1);
		glfwPollEvents();
		while (std::chrono::steady_clock::now().time_since_epoch().count() - tpr <= ticklength);
	}

	glfwDestroyWindow(w1);
	glfwTerminate();
	exit(EXIT_SUCCESS);

	thread_update.join();
}