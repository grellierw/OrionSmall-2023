#ifndef _disks_HPP_
#define _disks_HPP_
#include "api.h"


//Vars
extern bool cata_auto_shoot;
extern bool catahold;
//Funtions
void cataAuto(void);
void cataShoot();
void setCata(int motorPower);
void rollerChange(char colour);


#endif