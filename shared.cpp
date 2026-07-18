
#include "shared.h"

DIGITALKHATT_FONT_EXPORT Automedina* font_create(OtLayout* layout, MPFont* font, bool extended) {
    try {
        return new indopak::IndoPak(layout, font, extended);
    }
    catch (...) {
        return nullptr;
    };
}
