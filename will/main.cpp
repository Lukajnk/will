#include <chrono>
#include <thread>
#include <iostream>
#include "GLFW\glfw3.h"

GLFWwindow *w1;
std::thread thread_update;
bool loop = true;
long long point_A, point_U, point_R;

bool mForward	= false;
bool mBack		= false;
bool rLeft		= false;
bool rRight		= false;


void setup()
{
	glfwInit();

	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int screen_width = mode->width;
	int screen_height = mode->height;
	int window_width = screen_width / 2;
	int window_height = screen_height / 2;

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DECORATED, false);
	glfwWindowHint(GLFW_RESIZABLE, false);
	//glfwWindowHint(GLFW_SAMPLES, 4);

	w1 = glfwCreateWindow(window_width, window_height, "Gillow", 0, 0);

	glfwSetWindowPos(w1, window_width / 2, window_height / 2);
	glfwSetInputMode(w1, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(w1);

	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 100, 0, 100, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


void update()
{
	while (loop)
	{
		point_U = std::chrono::steady_clock::now().time_since_epoch().count();

		if (glfwGetKey(w1, GLFW_KEY_ESCAPE) == true) {
			loop = false;
		}

		if (glfwGetKey(w1, GLFW_KEY_W) == true) {
			mForward = true;
		} else {
			mForward = false;
		}

		if (glfwGetKey(w1, GLFW_KEY_S) == true) {
			mBack = true;
		} else {
			mBack = false;
		}

		if (glfwGetKey(w1, GLFW_KEY_A) == true) {
			rLeft = true;
		} else {
			rLeft = false;
		}

		if (glfwGetKey(w1, GLFW_KEY_D) == true) {
			rRight = true;
		} else {
			rRight = false;
		}

		while (std::chrono::steady_clock::now().time_since_epoch().count() - point_U <= 40000000);
	}
}


void render()
{
	glColor3f(0.4, 0.25, 0.3);
	glBegin(GL_TRIANGLES);

	glVertex2i(1, 2);
	glVertex2i(99, 2);
	glVertex2i(1, 98);

	glVertex2i(99, 98);
	glVertex2i(99, 2);
	glVertex2i(1, 98);
	glEnd();
}


int main() 
{
	point_A = std::chrono::steady_clock::now().time_since_epoch().count();

	setup();

	std::thread thread_update(update);

	while (loop)
	{
		point_R = std::chrono::steady_clock::now().time_since_epoch().count();

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		render();

		glfwSwapBuffers(w1);
		glfwPollEvents();

		while (std::chrono::steady_clock::now().time_since_epoch().count() - point_R <= 16666667);
	}

	thread_update.join();

	glfwDestroyWindow(w1);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}