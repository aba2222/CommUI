#include "widget.h"

Widget::~Widget() {
#ifdef _WIN32
    if (hFont != NULL) DeleteObject(hFont);
#endif  // _WIN32
}

void Widget::AddChild(std::shared_ptr<Widget> child) {
    children.push_back(child);
}
