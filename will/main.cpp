#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>
#include "GLFW\glfw3.h"

GLFWwindow *w1;
std::thread thread_update;
bool loop = true;
long long point_A, point_U, point_R, point_S;

bool mLeft		= false;
bool mRight		= false;

int player_x = 200;
int player_y = 60;
float player_r = 1.0;
float player_g = 0.5;
float player_b = 1.0;

short shots = 0;

int shot_1_x = 200;
int shot_1_y = 610;
int shot_2_x = 200;
int shot_2_y = 610;
int shot_3_x = 200;
int shot_3_y = 610;

void setup()
{
	glfwInit();

	const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int screen_width = mode->width;
	int screen_height = mode->height;
	int window_width = 400;
	int window_height = 600;

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DECORATED, false);
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_SAMPLES, 4);

	w1 = glfwCreateWindow(window_width, window_height, "Gillow", 0, 0);

	glfwSetWindowPos(w1, screen_width/2 - window_width/2, screen_height/2 - window_height/2);
	glfwSetInputMode(w1, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(w1);

	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 399, 0, 599, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


void update()
{
	while (loop)
	{
		point_U = std::chrono::steady_clock::now().time_since_epoch().count();

		if (glfwGetKey(w1, GLFW_KEY_ESCAPE) > 0) {
			loop = false;
		}

		if (glfwGetKey(w1, GLFW_KEY_LEFT) > 0) {
			mLeft = true;
		} else {
			mLeft = false;
		}

		if (glfwGetKey(w1, GLFW_KEY_RIGHT) > 0) {
			mRight = true;
		} else {
			mRight = false;
		}
		
		if (glfwGetKey(w1, GLFW_KEY_SPACE) > 0 && std::chrono::steady_clock::now().time_since_epoch().count() - point_S > 250000000) {
			if (shot_1_y > 600) {
				shot_1_x = player_x;
				shot_1_y = player_y + 50;
				point_S = std::chrono::steady_clock::now().time_since_epoch().count();
			} else if (shot_2_y > 600) {
				shot_2_x = player_x;
				shot_2_y = player_y + 50;
				point_S = std::chrono::steady_clock::now().time_since_epoch().count();
			} else if (shot_3_y > 600) {
				shot_3_x = player_x;
				shot_3_y = player_y + 50;
				point_S = std::chrono::steady_clock::now().time_since_epoch().count();
			}
		}

		if (mLeft == true && mRight == false)
		{
			if (player_x > 36)
			{
				player_x -= 4;
			}
		}
		else if (mRight == true && mLeft == false) {
			if (player_x < 365)
			{
				player_x += 4;
			}
		}
		
		if (shot_1_y > 0 && shot_1_y < 605) {
			shot_1_y += 10;
		}

		if (shot_2_y > 0 && shot_2_y < 605) {
			shot_2_y += 10;
		}
		
		if (shot_3_y > 0 && shot_3_y < 605) {
			shot_3_y += 10;
		}

		while (std::chrono::steady_clock::now().time_since_epoch().count() - point_U <= 16666667);
	}
}


void render()
{
	glLineWidth(1);

	glBegin(GL_LINES);

	glColor3f(1.0, 1.0, 1.0);

	//borders
	glVertex2i(0, 0);
	glVertex2i(0, 599);

	glVertex2i(0, 0);
	glVertex2i(399, 0);

	glVertex2i(399, 0);
	glVertex2i(399, 599);

	glVertex2i(0, 599);
	glVertex2i(399, 599);

	glVertex2i(0, 34);
	glVertex2i(399, 34);

	//plane
	glVertex2i(player_x, player_y + 10);
	glVertex2i(player_x - 20, player_y);

	glVertex2i(player_x, player_y + 10);
	glVertex2i(player_x + 20, player_y);

	glVertex2i(player_x, player_y + 45);
	glVertex2i(player_x - 20, player_y);

	glVertex2i(player_x, player_y + 45);
	glVertex2i(player_x + 20, player_y);

	//shots
	glVertex2i(shot_1_x, shot_1_y);
	glVertex2i(shot_1_x, shot_1_y + 5);

	glVertex2i(shot_2_x, shot_2_y);
	glVertex2i(shot_2_x, shot_2_y + 5);

	glVertex2i(shot_3_x, shot_3_y);
	glVertex2i(shot_3_x, shot_3_y + 5);

	glEnd();
}


int main() 
{
	FreeConsole();
	point_A = std::chrono::steady_clock::now().time_since_epoch().count();

	setup();

	std::thread thread_update(update);

	while (loop)
	{
		point_R = std::chrono::steady_clock::now().time_since_epoch().count();

		glClearColor(0.0, 0.0, 0.0, 1.0);
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