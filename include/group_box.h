#pragma once
#include "widget.h"

class IGroupBox : public Widget {
public:
	IGroupBox(std::shared_ptr<Widget> parent) : Widget(parent) {}
	virtual ~IGroupBox() = default;
	virtual void Create(const char* name, int width, int height, int x = -1, int y = -1) = 0;
};

#ifdef _WIN32
#include <windows.h>
class WinGroupBox : public IGroupBox {  
public:  
	WinGroupBox(std::shared_ptr<Widget> parent) : IGroupBox(parent) {}  
	~WinGroupBox() = default;
	void Create(const char* name, int width, int height, int x = -1, int y = -1) override;  
};
#endif

std::shared_ptr<IGroupBox> CreateGroupBoxInstance(std::shared_ptr<Widget> parent);