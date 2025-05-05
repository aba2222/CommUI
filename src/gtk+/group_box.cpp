#ifdef __linux__
#include "group_box.h"

namespace CommUI {
void CustomGtkGroupBox::Create(const char* name, int width, int height, int x, int y) {
    widget = gtk_frame_new(name);
    gtk_widget_set_size_request(widget, width, height);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(widget), fixed);

    gtk_fixed_put(GTK_FIXED(parent->GetFixed()), widget, x, y);

    gtk_frame_set_label_align(GTK_FRAME(widget), 0.5, 0.5);              // Center the label
    gtk_frame_set_shadow_type(GTK_FRAME(widget), GTK_SHADOW_ETCHED_IN);  // The shadow type

    gtk_widget_show(widget);
}

std::shared_ptr<IGroupBox> CreateGroupBoxInstance(std::shared_ptr<Widget> parent) {
    return std::make_shared<CustomGtkGroupBox>(parent);
}
}  // namespace CommUI
#endif