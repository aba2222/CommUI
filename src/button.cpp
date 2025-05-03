#include "button.h"

WinButton::~WinButton() {
	//UnregisterClass(name, hInst);
}

void WinButton::Create(const char* name, int width, int height, int x, int y) {  
   HWND parentHwnd = parent ? parent->GetHwnd() : nullptr;  
   if (parentHwnd == nullptr) {  
       MessageBox(NULL, "¸¸´°¿Ú¾ä±úÎÞÐ§", "´íÎó", MB_OK);  
       return;  
   } 

   hFont = CreateFontW(-16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
       DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
       DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Segoe UI");
   hwnd = CreateWindow(  
       "BUTTON",  // Predefined class; Unicode assumed   
       "OK",      // Button text   
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles   
       x,          // x position   
       y,          // y position   
       width,      // Button width  
       height,     // Button height  
       parentHwnd, // Parent window  
       NULL,       // No menu.  
       (HINSTANCE)GetWindowLongPtr(parentHwnd, GWLP_HINSTANCE),  
       NULL);      // Pointer not needed.  
   SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, TRUE);
   if (hwnd == NULL) {  
       MessageBox(NULL, "´°¿Ú´´½¨Ê§°Ü", "´íÎó", MB_OK);  
   }  
}

std::shared_ptr<IButton> CreateButtonInstance(std::shared_ptr<Widget> parent) {
#ifdef _WIN32
    return std::make_unique<WinButton>(parent);
#else
    return std::make_unique<LinuxButton>();
#endif
}