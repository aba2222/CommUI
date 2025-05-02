#pragma once
#include <iostream>

class IWindow {
public:
    virtual ~IWindow() = default;
    virtual void Create(const char* name, int width, int height) = 0;
    virtual void Run() = 0;
};

#ifdef _WIN32
#include <windows.h>

class WinWindow : public IWindow {
public:
    ~WinWindow();
    void Create(const char* name, int width, int height) override;
    void Run() override;

private:
    HWND hwnd = nullptr;
    HINSTANCE hInst = nullptr;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) noexcept;
};

#endif

std::unique_ptr<IWindow> CreateWindowInstance();