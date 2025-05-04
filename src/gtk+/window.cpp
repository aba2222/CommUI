#include "window.h"
#include <iostream>

namespace CommonUI {
void CustomGtkWindow::Create(const char* name, int width, int height, int x, int y) {
    std::cout << "Creating GTK+ window: " << name << std::endl;
    gtk_init(nullptr, nullptr);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), name);
    gtk_window_set_default_size(GTK_WINDOW(window), width, height);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
    gtk_window_set_decorated(GTK_WINDOW(window), TRUE);
    gtk_window_set_type_hint(GTK_WINDOW(window), GDK_WINDOW_TYPE_HINT_DIALOG);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);

    // 添加关闭信号
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), nullptr);
}

void CustomGtkWindow::Run() {
    std::cout << "Running GTK+ window" << std::endl;
    gtk_widget_show_all(window);
    gtk_main();
}

std::shared_ptr<IWindow> CreateWindowInstance() {
    return std::make_shared<CustomGtkWindow>();
}
}