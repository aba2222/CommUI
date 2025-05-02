#include "widget.h"

void Widget::AddChild(std::shared_ptr<Widget> child) {
	children.push_back(child);
}
