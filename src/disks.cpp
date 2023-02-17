#include "main.h"


//Cata
//auto
PID acataPID{0.45, 0, 0, 0, "autoCata"};

void cataAuto(double target) {
  acataPID.set_target(target);
  ez::exit_output exit = ez::RUNNING;
  while (acataPID.exit_condition({Lcata, Rcata}, true) == ez::RUNNING) {
    double output = acataPID.compute(cataRotation.get_angle());
    setCata(output);
    pros::delay(ez::util::DELAY_TIME);
  }
  setCata(0);
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