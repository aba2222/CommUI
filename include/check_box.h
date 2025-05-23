#pragma once
#include "widget.h"

namespace CommUI {
class ICheckBox : public Widget {
public:
    ICheckBox(std::shared_ptr<Widget> parent) : Widget(parent) {}
    virtual ~ICheckBox() = default;
    virtual void Create(const char* name, int width, int height, int x = -1, int y = -1) = 0;
};

#ifdef _WIN32
#include <windows.h>
class WinCheckBox : public ICheckBox {
public:
    WinCheckBox(std::shared_ptr<Widget> parent) : ICheckBox(parent) {}
    ~WinCheckBox() = default;
    void Create(const char* name, int width, int height, int x = -1, int y = -1) override;
};
#elif __linux__
#include <gtk/gtk.h>
class CustomGtkCheckBox : public ICheckBox {
public:
    CustomGtkCheckBox(std::shared_ptr<Widget> parent) : ICheckBox(parent) {}
    ~CustomGtkCheckBox() = default;
    void Create(const char* name, int width, int height, int x = -1, int y = -1) override;
};
#endif

std::shared_ptr<ICheckBox> CreateCheckBoxInstance(std::shared_ptr<Widget> parent);
}  // namespace CommUI