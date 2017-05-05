#include <iostream>
#include <chrono>
#include "GLFW\glfw3.h"

extern bool loop;
extern long ticklength;
extern GLFWwindow *w1;

void update() 
{
	long long tpu;

	while (loop)
	{
		tpu = std::chrono::steady_clock::now().time_since_epoch().count();
		std::cout << "u ";

		if (glfwGetKey(w1, GLFW_KEY_ESCAPE) == true) {
			loop = false;
		}

		while (std::chrono::steady_clock::now().time_since_epoch().count() - tpu <= ticklength);
	}
}