#include <iostream>
#include <chrono>

#define currenttime std::chrono::steady_clock::now().time_since_epoch().count()

void input();

extern bool loop;
extern long ticklength;
long long tp1;

void update() {
	std::cout << "update works" << std::endl;
	while (loop) {
		tp1 = currenttime;

		input();

		std::cout << "update" << std::endl;

		while (currenttime - tp1 <= ticklength);
	}
}