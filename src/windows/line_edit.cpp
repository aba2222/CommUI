#ifdef  _WIN32
#include "line_edit.h"
namespace CommUI {
void WinLineEdit::Create(const char* name, int width, int height, int x, int y) {
    HWND parentHwnd = parent ? parent->GetHwnd() : nullptr;
    if (parentHwnd == nullptr) {
        MessageBox(NULL, "The parent control is invalid", "Error", MB_OK);
        return;
    }

    hFont = CreateFontW(-16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                        DEFAULT_PITCH | FF_DONTCARE, L"Segoe UI Variable");
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_LEFT, x, y, width, height, parentHwnd, NULL, NULL, NULL);
    SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, TRUE);
    if (hwnd == NULL) {
        MessageBox(NULL, "¿Ø¼þ´´½¨Ê§°Ü", "´íÎó", MB_OK);
    }
}

std::shared_ptr<ILineEdit> CreateLineEditInstance(std::shared_ptr<Widget> parent) {
    return std::make_shared<WinLineEdit>(parent);
}
} // namespace CommUI
#endif  //  _WIN32