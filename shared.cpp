
#include "shared.h"

__declspec(dllexport) Automedina* __stdcall font_create(OtLayout* layout, Font* font, bool extended) {
    try {
        return new indopak::IndoPak(layout, font, extended);
    }
    catch (...) {
        return nullptr;
    };
}