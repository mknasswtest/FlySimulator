#include "sterowanie.h"

static int elevator_counter = 0;

int update_elevator(int elevator) {
    elevator_counter++;
    if (elevator_counter >= 3) {
        if (elevator > 0) elevator--;
        else if (elevator < 0) elevator++;
        elevator_counter = 0;
    }
    return elevator;
}

int update_flaps(int flaps, char key) {
    if (key == 'f' && flaps > 0) flaps -= 10;
    if (key == 'g' && flaps < 100) flaps += 10;
    return flaps;
}

int get_flap_drag_factor(int flaps) {
    return 100.0 + flaps;
}

double get_flap_lift_bonus(int flaps) {
    return flaps * 0.02;
}