#include <iostream>
#include "window.h"

int main() {
	std::cout << "Hello, World!" << std::endl;
	std::unique_ptr<IWindow> my_window = CreateWindowInstance();
	my_window->Create("My Window", 800, 600);
	my_window->Run();

	return 0;
}