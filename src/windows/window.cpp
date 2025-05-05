#include "window.h"

namespace CommonUI {
#ifdef _WIN32
WinWindow::~WinWindow() {
    if (hwnd) {
        DestroyWindow(hwnd);
    }
}

void WinWindow::Create(const char* name, int width, int height, int x, int y) {
    hInst = GetModuleHandle(NULL);
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = name;
    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, name, name, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width,
                          height, NULL, NULL, wc.hInstance, this);

    if (hwnd == NULL) {
        MessageBox(NULL, "���ڴ���ʧ��", "����", MB_OK);
    } else {
        ShowWindow(hwnd, SW_SHOWNORMAL);
        UpdateWindow(hwnd);
    }
}

void WinWindow::Run() {
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK WinWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                                       LPARAM lParam) noexcept {
    switch (uMsg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
};
#endif

std::shared_ptr<CommonUI::IWindow> CommonUI::CreateWindowInstance() {
#ifdef _WIN32
    return std::make_shared<WinWindow>();
#endif
#ifdef __linux__
    return std::make_shared<CommonUI::CustomGtkWindow>();
#endif
}
}  // namespace CommonUI