#include <iostream>
#include <chrono>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#define currenttime std::chrono::steady_clock::now().time_since_epoch().count()

extern GLFWwindow* w1;

extern bool loop;
extern long ticklength;
long long tp2;

void render() {

	std::cout << "render works" << std::endl;

	glfwInit();
	//glfwWindowHint(GLFW_DECORATED, false);

	GLFWvidmode *mode;
	mode = (GLFWvidmode*)glfwGetVideoMode(glfwGetPrimaryMonitor());

	w1 = glfwCreateWindow(mode->width / 2, mode->height / 2, "will", NULL, NULL);
	glfwSetWindowPos(w1, mode->width / 4, mode->height / 4);

	glfwMakeContextCurrent(w1);
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(w1) && loop) {

		tp2 = currenttime;

		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(w1);
		glfwPollEvents();

		std::cout << "render" << std::endl;

		while (currenttime - tp2 <= ticklength);
	}

	glfwDestroyWindow(w1);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}