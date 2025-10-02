#include <stdio.h>
#include "kokpit.h"

void draw_cockpit(int throttle, double rpm, double mixture, double speed, int elevator, double pitch, double climb_rate, double altitude, int flaps, int engine_on) {
    printf("=== FLIGHT COCKPIT ===\n");
    printf("Engine: %s\n", engine_on ? "ON" : "OFF");
    printf("Throttle: %d%%\n", throttle);
    printf("RPM: %.1f\n", rpm);
    printf("Mixture: %.2f\n", mixture);
    printf("Speed: %.1f knots\n", speed);
    printf("Elevator: %d\n", elevator);
    printf("Pitch: %.1f degrees\n", pitch);
    printf("Climb Rate: %.1f m/s\n", climb_rate);
    printf("Altitude: %.1f m\n", altitude);
    printf("Flaps: %d%%\n", flaps);
    printf("Controls: [i] ignition, [ ] throttle, [w/s] elevator, [f/g] flaps\n");
}