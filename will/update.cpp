#include <iostream>
#include <chrono>

void input();

extern bool loop;
extern long ticklength;
long long tp1;

void update() 
{
	while (loop)
	{
		tp1 = std::chrono::steady_clock::now().time_since_epoch().count();

		std::cout << "u ";

		while (std::chrono::steady_clock::now().time_since_epoch().count() - tp1 <= ticklength);
	}
}