
#ifndef LOT_H
#define LOT_H

double update_pitch(double pitch, int elevator, double speed);
double update_speed(double rpm, double pitch, double current_speed, int flaps);
double update_climb_rate(double speed, double pitch, int flaps);
double update_altitude(double altitude, double climb_rate);


#endif
