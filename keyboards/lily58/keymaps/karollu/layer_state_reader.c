#include "quantum.h"
#include "keymap_user.h"

const char *read_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case BASE:
            return "L: Base";
        case EXTRA:
            return "L: Extra";
        case TAP:
            return "L: Tap";
        case BTN:
            return "L: Btn";
        case NAV:
            return "L: Nav";
        case MOUSE:
            return "L: Mouse";
        case MEDIA:
            return "L: Media";
        case NUM:
            return "L: Num";
        case FUN:
            return "L: Fun";
        case SPEC:
            return "L: Spec";
        default:
            return "L: Undef";
    }
}
