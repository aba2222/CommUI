#include "window.h"

#include <iostream>

namespace CommonUI {
void CustomGtkWindow::Create(const char* name, int width, int height, int x, int y) {
    std::cout << "Creating GTK+ window: " << name << std::endl;
    gtk_init(nullptr, nullptr);
    widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(widget), name);
    gtk_window_set_default_size(GTK_WINDOW(widget), width, height);
    gtk_window_set_position(GTK_WINDOW(widget), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(widget), TRUE);
    gtk_window_set_decorated(GTK_WINDOW(widget), TRUE);
    gtk_window_set_type_hint(GTK_WINDOW(widget), GDK_WINDOW_TYPE_HINT_DIALOG);
    gtk_window_set_modal(GTK_WINDOW(widget), TRUE);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(widget), fixed);

    // 添加关闭信号
    g_signal_connect(widget, "destroy", G_CALLBACK(gtk_main_quit), nullptr);
}

void CustomGtkWindow::Run() {
    std::cout << "Running GTK+ window" << std::endl;
    gtk_widget_show_all(widget);
    gtk_main();
}

std::shared_ptr<IWindow> CreateWindowInstance() {
    return std::make_shared<CustomGtkWindow>();
}
}  // namespace CommonUI