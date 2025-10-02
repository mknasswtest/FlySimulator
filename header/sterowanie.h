#ifndef STEROWANIE_H
#define STEROWANIE_H

int update_elevator(int elevator);
int update_flaps(int flaps, char key);
int get_flap_drag_factor(int flaps);
double get_flap_lift_bonus(int flaps);

#endif