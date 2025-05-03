#pragma once  
#include <memory>  
#include <vector>
#ifdef _WIN32
#include <Windows.h>
#endif

class Widget {
public:
   Widget(std::shared_ptr<Widget> parent) : parent(parent) {}  
   ~Widget();
   virtual void Create(const char* name, int width, int height, int x = -1, int y = -1) = 0;  
   void AddChild(std::shared_ptr<Widget> child);
#ifdef _WIN32
   HWND GetHwnd() const noexcept { return hwnd; }
#endif


private:  
   unsigned int id = 0;
#ifdef _WIN32
protected:
	HWND hwnd = nullptr;
	HFONT hFont = nullptr;
#endif

protected:  
   std::vector<std::shared_ptr<Widget>> children;
   std::shared_ptr<Widget> parent;
};