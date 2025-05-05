#include <iostream>

#include "button.h"
#include "check_box.h"
#include "group_box.h"
#include "line_edit.h"
#include "window.h"

#ifdef _WIN32
#pragma comment(linker, \
                "\"/manifestdependency:type='win32' \
				name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
				processorArchitecture='*' publicKeyToken='6595b64144ccf1df' \
				language='*'\"")
#endif  // _WIN32

int main() {
    std::cout << "CommUI Demo is running..." << std::endl;
    std::shared_ptr<CommUI::IWindow> demo_window = CommUI::CreateWindowInstance();
    demo_window->Create("CommUI Demo", 800, 600);

    std::shared_ptr<CommUI::IGroupBox> demo_group_box = CommUI::CreateGroupBoxInstance(demo_window);
    demo_group_box->Create("Demo Group Box", 200, 200, 10, 10);

    std::shared_ptr<CommUI::ICheckBox> demo_check_box = CommUI::CreateCheckBoxInstance(demo_group_box);
    std::shared_ptr<CommUI::IButton> demo_button = CommUI::CreateButtonInstance(demo_group_box);
    std::shared_ptr<CommUI::ILineEdit> demo_line_edit = CommUI::CreateLineEditInstance(demo_group_box);
    demo_check_box->Create("Check Me", 100, 40, 10, 5);
    demo_button->Create("OK", 100, 40, 10, 50);
   demo_line_edit->Create("Enter Text", 100, 20, 10, 95);

    demo_window->Run();

    return 0;
}