#ifndef _disks_HPP_
#define _disks_HPP_
#include "api.h"
#include "EZ-Template/PID.hpp"

//Cata
void cataAuto(void);
extern bool catahold;
void cataShoot();
extern bool cata_auto_shoot;
//Helper

void setCata(int motorPower);
void rollerChange(char colour);






#endif