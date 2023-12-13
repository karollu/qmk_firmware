(#include "quantum.h"
#include "keymap_user.h"

const char *read_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case BASE:
            return "Layer: Base";
        case EXTRA:
            return "Layer: Extra";
        case TAP:
            return "Layer: Tap";
        case BTN:
            return "Layer: Btn";
        case NAV:
            return "Layer: Nav";
        case MOUSE:
            return "Layer: Mouse";
        case MEDIA:
            return "Layer: Media";
        case NUM:
            return "Layer: Num";
        case SYM:
            return "Layer: Sym";
        case FUN:
            return "Layer: Fun";
        case SPEC:
            return "Layer: Spec";
        default:
            return "Layer: Undef";
    }
}
