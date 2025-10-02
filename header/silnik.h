#ifndef SILNIK_H
#define SILNIK_H

int update_throttle(int throttle, char key);
double calculate_target_rpm(int throttle);
double update_rpm(double rpm, double target_rpm);
double calculate_mixture(int throttle);

#endif