// Bring information from header files
#include "vex.h"
#include "bot-functions.h"
using namespace vex;

// define your global instances of motors and other devices here
motor LeftDrive = motor(PORT1 , ratio18_1, false);
motor RightDrive = motor(PORT10 , ratio18_1, true);
motor Arm = motor(PORT8 , ratio18_1, false);
motor Claw = motor(PORT3 , ratio18_1, true); // Positive to open
controller mainControl = controller(primary);
brain Brain;


void setDriveBrake (vex::brakeType braking){    // Can be brake, coast, hold
    LeftDrive.setStopping(braking);
    RightDrive.setStopping(braking);
}



// ========= Drivetrain Time-Based Functions ========= //
void goFwdTime (int time, int velocity){
    // Switch motors on
    LeftDrive.spin(directionType::fwd, velocity, pct);
    RightDrive.spin(directionType::fwd, velocity, pct);

    wait(time, msec);   // Leave motors on for some 'time'

    // Turn motors off
    LeftDrive.stop();
    RightDrive.stop();

    wait(WAIT_AFTER_DRIVE, msec);
}

void goBackTime (int time, int velocity){
    // insert function definition here
}

void turnLeftTime (int time){
    // insert function definition here
}
void turnRightTime (int time){
    // insert function definition here
}



// ========= Drivetrain Encoder-Based Functions ========= //
void goFwdEnc (float inches, int velocity){
    // Calculate how many degrees to turn (call this 'numberDeg')
    float numberDeg = (inches/WHEEL_CIRCUMFERENCE) * 360;   // (# of revolutions) * 360 = (# of degrees)

    // Spin drive motors 'numberDeg' degrees
    LeftDrive.spinFor (numberDeg, rotationUnits::deg, velocity, velocityUnits::pct, false);
    RightDrive.spinFor (numberDeg, rotationUnits::deg, velocity, velocityUnits::pct);

    wait(WAIT_AFTER_DRIVE, msec);
}

void goBackEnc (float inches, int velocity){
    // insert function definition here
}

void turnLeftEnc(float degree){
    // insert function definition here
}

void turnRightEnc(float degree){
    // insert function definition here
}



// ========= Arm Time-Based Functions ========= //
void armUpTime (int time){
    // insert function definition here
}

void armDownTime (int time){
    // insert function definition here
}




// ========= Arm Encoder-Based Functions ========= //
void armUpEnc (float degrees){
    // insert function definition here
}

void armDownEnc (float degrees){
    // insert function definition here
}




// =============== Claw Control =============== //
void clawOpen() {
    // insert function definition here
}

void clawClose(){
    // insert function definition here
}