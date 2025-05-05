#include "check_box.h"

namespace CommUI {
void CustomGtkCheckBox::Create(const char* name, int width, int height, int x, int y) {
    widget = gtk_check_button_new_with_label(name);
    gtk_widget_set_size_request(widget, width, height);
    gtk_fixed_put(GTK_FIXED(parent->GetFixed()), widget, x, y);
    gtk_widget_show(widget);
}

std::shared_ptr<ICheckBox> CreateCheckBoxInstance(std::shared_ptr<Widget> parent) {
    return std::make_shared<CustomGtkCheckBox>(parent);
}
}  // namespace CommUI