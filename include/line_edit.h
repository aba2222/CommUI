#pragma once
#include "widget.h"

namespace CommUI {
class ILineEdit : public Widget {
public:
    ILineEdit(std::shared_ptr<Widget> parent) : Widget(parent) {}
    virtual ~ILineEdit() = default;
    virtual void Create(const char* name, int width, int height, int x = -1, int y = -1) = 0;
};

#ifdef _WIN32
#include <windows.h>
class WinLineEdit : public ICheckBox {
public:
    WinCheckBox(std::shared_ptr<Widget> parent) : ICheckBox(parent) {}
    ~WinCheckBox() = default;
    void Create(const char* name, int width, int height, int x = -1, int y = -1) override;
};
#elif __linux__
#include <gtk/gtk.h>
class CustomGtkLineEdit : public ILineEdit {
public:
    CustomGtkLineEdit(std::shared_ptr<Widget> parent) : ILineEdit(parent) {}
    ~CustomGtkLineEdit() = default;
    void Create(const char* name, int width, int height, int x = -1, int y = -1) override;
};
#endif

std::shared_ptr<ILineEdit> CreateLineEditInstance(std::shared_ptr<Widget> parent);
}  // namespace CommUI