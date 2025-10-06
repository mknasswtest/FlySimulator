#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "silnik.h"
#include "lot.h"
#include "kokpit.h"
#include "sterowanie.h"

int main() {
    int throttle = 0;
    int elevator = 0;
    int flaps = 100.0;
    double rpm = 600;
    double speed = 0;
    double pitch = 0;
    double climb_rate = 0;
    double altitude = 0;
    int mixture = 0.8;
    int engine_on = 0;

    while (1) {
        if (_kbhit()) {
            char key = _getch();

            if (!engine_on && key == 'i') {
                engine_on = 1;
                throttle = 10;
                mixture = calculate_mixture(throttle);
            }

            if (engine_on) {
                throttle = update_throttle(throttle, key);
                flaps = update_flaps(flaps, key);
                if (key == 'w' && elevator < 4) elevator++;
                if (key == 's' && elevator > -4) elevator--;
            }
        }

        if (engine_on) {
            double target_rpm = calculate_target_rpm(throttle);
            rpm = update_rpm(rpm, target_rpm);
            mixture = calculate_mixture(throttle);
            speed = update_speed(rpm, pitch, speed, flaps);
            elevator = update_elevator(elevator);
            pitch = update_pitch(pitch, elevator, speed);
            climb_rate = update_climb_rate(speed, pitch, flaps);
            altitude = update_altitude(altitude, climb_rate);
        }

        system("cls");
        draw_cockpit(throttle, rpm, mixture, speed, elevator, pitch, climb_rate, altitude, flaps, engine_on);
        Sleep(200);
    }

    return 0;
}