#include <math.h>
#include "silnik.h"

int update_throttle(int throttle, char key) {
    if (key == '[' && throttle > 10) throttle -= 5;
    if (key == ']' && throttle < 100) throttle += 5;
    return throttle;
}

double calculate_target_rpm(int throttle) {
    return 600 + pow((throttle - 10) / 90.0, 0.7) * 3400;
}

double update_rpm(double rpm, double target_rpm) {
    return rpm + (target_rpm - rpm) * 0.05;
}

double calculate_mixture(int throttle) {
    return 0.8 + (throttle / 100.0) * 0.4;
}