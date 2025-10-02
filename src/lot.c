#include <math.h>
#include "lot.h"
#include "sterowanie.h"

#define PI 3.14159265

double update_pitch(double pitch, int elevator, double speed) {
    double max_pitch = 4.0 + (speed / 80.0) * (30.0 - 4.0);
    if (max_pitch > 30.0) max_pitch = 30.0;
    pitch += elevator * 0.2;
    if (pitch > max_pitch) pitch = max_pitch;
    if (pitch < -max_pitch) pitch = -max_pitch;
    return pitch;
}

double update_speed(double rpm, double pitch, double current_speed, int flaps) {
    double drag_factor = 1.0 - fabs(pitch) / 60.0;
    drag_factor *= 100.0 / get_flap_drag_factor(flaps);
    double target_speed = (rpm - 600) / 3400.0 * 100.0 * drag_factor;
    return current_speed + (target_speed - current_speed) * 0.05;
}

double update_climb_rate(double speed, double pitch, int flaps) {
    double lift_force;
    if (speed < 10.0) {
        lift_force = -10.0 * (1.0 - speed / 10.0);
    } else {
        lift_force = speed * 0.05;
    }
    lift_force += get_flap_lift_bonus(flaps);
    return (speed * sin(pitch * PI / 180.0)) + lift_force;
}

double update_altitude(double altitude, double climb_rate) {
    altitude += climb_rate * 0.2;
    if (altitude < 0.0) altitude = 0.0;
    return altitude;
}