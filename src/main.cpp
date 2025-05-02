#include <iostream>
#include "window.h"
#include "button.h"

int main() {
	std::cout << "Hello, World!" << std::endl;
	std::shared_ptr<IWindow> my_window = CreateWindowInstance();
	my_window->Create("My Window", 800, 600);
	std::shared_ptr<IButton> my_button = CreateButtonInstance(my_window);
	my_button->Create("OK", 100, 50, 10, 10);
	my_window->Run();

	return 0;
}