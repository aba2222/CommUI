#pragma once
#include <functional>

#include "widget.h"

namespace CommUI {
class IButton : public Widget {
public:
    IButton(std::shared_ptr<Widget> parent) : Widget(parent) {}
    virtual ~IButton() = default;
    virtual void Create(const char* name, int width, int height, int x = -1, int y = -1) = 0;

private:
    std::function<void(int)> onClick;
};

#ifdef _WIN32
#include <windows.h>
class WinButton : public IButton {
public:
    WinButton(std::shared_ptr<Widget> parent) : IButton(parent){};
    ~WinButton();
    void Create(const char* name, int width, int height, int x = -1, int y = -1) override;
};
#elif __linux__
#include <gtk/gtk.h>
class CustomGtkButton : public IButton {
public:
    CustomGtkButton(std::shared_ptr<Widget> parent) : IButton(parent) {}
    ~CustomGtkButton() = default;
    void Create(const char* name, int width, int height, int x = -1, int y = -1) override;
};
#endif

std::shared_ptr<IButton> CreateButtonInstance(std::shared_ptr<Widget> parent);
}  // namespace CommUI