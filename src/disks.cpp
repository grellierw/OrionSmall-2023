#include "main.h"


//Cata
bool catahold = true;
bool cata_auto_shoot = false;
//auto

PID acataPID{0.1, 0, 0.4, 0, "autoCata"};

void cataAuto(void) {
  
  while (catahold) {
    acataPID.set_target(8400);
    setCata(abs(acataPID.compute(cataRotation.get_angle())));
    pros::c::delay(10);

    if(cata_auto_shoot){
      setCata(127);
        pros::c::delay(150);
        setCata(0);
        cata_auto_shoot = false;

    }
}
}
    void cataShoot(){
    pros::c::delay(1000);
    cata_auto_shoot = true;
    pros::c::delay(10);
    cata_auto_shoot = false;
    }

   



//Roller

void rollerChange(char colour){
    rollerSense.set_led_pwm(100);
    pros::c::optical_rgb_s_t rollerColour;
    int timeStart = pros::c::millis();
    if(colour == 'b'){
        rollerColour = rollerSense.get_rgb(); 
        while(rollerColour.red < 10000 && timeStart < pros::c::millis()+2000)
        {
            Tintake = 60;
            rollerColour = rollerSense.get_rgb();
        }
    }
    Tintake = 0;
    rollerSense.set_led_pwm(0);
}




//Helper

void setCata(int motorPower){
    Rcata.move(motorPower);
    Lcata.move(motorPower);
}