#include "line_edit.h"

namespace CommUI {
void CustomGtkLineEdit::Create(const char* name, int width, int height, int x, int y) {
    widget = gtk_entry_new();
    gtk_widget_set_size_request(widget, width, height);
    gtk_fixed_put(GTK_FIXED(parent->GetFixed()), widget, x, y);
    gtk_widget_show(widget);
}

std::shared_ptr<ILineEdit> CreateLineEditInstance(std::shared_ptr<Widget> parent) {
    return std::make_shared<CustomGtkLineEdit>(parent);
}
}  // namespace CommUI