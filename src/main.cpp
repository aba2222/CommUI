#include <iostream>
#include "window.h"
#include "button.h"
#include "group_box.h"
#include "check_box.h"

#ifdef _WIN32
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' \
language='*'\"")
#endif // _WIN32

int main() {
	std::cout << "Hello, World!" << std::endl;
	std::shared_ptr<CommonUI::IWindow> my_window = CommonUI::CreateWindowInstance();
	my_window->Create("My Window", 800, 600);

	//std::shared_ptr<CommonUI::IGroupBox> my_group_box = CommonUI::CreateGroupBoxInstance(my_window);
	//my_group_box->Create("My Group Box", 200, 200, 10, 10);

	/*std::shared_ptr<ICheckBox> my_check_box = CreateCheckBoxInstance(my_group_box);
	std::shared_ptr<IButton> my_button = CreateButtonInstance(my_group_box);
	my_check_box->Create("Check Me", 100, 40, 10, 30);
	my_button->Create("OK", 100, 50, 10, 70);*/

	my_window->Run();

	return 0;
}