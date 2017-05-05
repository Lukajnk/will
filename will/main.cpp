#include <chrono>
#include <thread>
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#define currenttime std::chrono::steady_clock::now().time_since_epoch().count()

std::thread thread1;
std::thread thread2;

bool loop = true;
long ticklength = 1000000000 / 30;
long long loopstart;

void setup();
void update();
void render();

GLFWwindow* w1;

int main() {

	loopstart = currenttime;

	setup();
	std::thread thread1(update);
	std::thread thread2(render);
	thread1.join();
	thread2.join();

	system("Pause");
}