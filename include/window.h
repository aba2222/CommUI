#pragma once
#include <iostream>
#include "widget.h"

class IWindow : public  Widget {
public:
    IWindow() : Widget(NULL){};
    virtual ~IWindow() = default;
    virtual void Create(const char* name, int width, int height, int x = -1, int y = -1) = 0;
    virtual void Run() = 0;
};

#ifdef _WIN32
#include <windows.h>

class WinWindow : public IWindow {
public:
    ~WinWindow();
    void Create(const char* name, int width, int height, int x = -1, int y = -1) override;
    void Run() override;

private:
    HINSTANCE hInst = nullptr;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) noexcept;
};

#endif

std::shared_ptr<IWindow> CreateWindowInstance();