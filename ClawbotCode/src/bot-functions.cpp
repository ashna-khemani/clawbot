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
    // Switch motors on
    LeftDrive.spin(directionType::rev, velocity, pct);
    RightDrive.spin(directionType::rev, velocity, pct);

    wait(time, msec);   // Leave motors on for some 'time'

    // Turn motors off
    LeftDrive.stop();
    RightDrive.stop();

    wait(WAIT_AFTER_DRIVE, msec);
}

void turnLeftTime (int time){
    // Switch motors on
    LeftDrive.spin(directionType::rev, TURNING_VELOCITY, pct);
    RightDrive.spin(directionType::fwd, TURNING_VELOCITY, pct);

    wait(time, msec);   // Leave motors on for some 'time'

    // Turn motors off
    LeftDrive.stop();
    RightDrive.stop();

    wait(WAIT_AFTER_DRIVE, msec);
}
void turnRightTime (int time){
    // Switch motors on
    LeftDrive.spin(directionType::fwd, TURNING_VELOCITY, pct);
    RightDrive.spin(directionType::rev, TURNING_VELOCITY, pct);

    wait(time, msec);   // Leave motors on for some 'time'

    // Turn motors off
    LeftDrive.stop();
    RightDrive.stop();

    wait(WAIT_AFTER_DRIVE, msec);
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
    // Calculate how many degrees to turn (call this 'numberDeg')
    float numberDeg = (inches/WHEEL_CIRCUMFERENCE) * 360;   // (# of revolutions) * 360 = (# of degrees)

    // Spin drive motors 'numberDeg' degrees
    LeftDrive.spinFor (reverse, numberDeg, rotationUnits::deg, velocity, velocityUnits::pct, false);
    RightDrive.spinFor (reverse, numberDeg, rotationUnits::deg, velocity, velocityUnits::pct);

    wait(WAIT_AFTER_DRIVE, msec);
}

void turnLeftEnc(float degree){
    float numberOfRevs = degree * REV_TO_ANGLE;
    setDriveBrake(hold);

    LeftDrive.spinFor(directionType::rev, numberOfRevs*360, rotationUnits::deg, TURNING_VELOCITY, velocityUnits::pct, false);
    RightDrive.spinFor(directionType::fwd, numberOfRevs*360, rotationUnits::deg, TURNING_VELOCITY, velocityUnits::pct);

    setDriveBrake(brake);
    wait(WAIT_AFTER_DRIVE, msec);
}

void turnRightEnc(float degree){
    float numberOfRevs = degree * REV_TO_ANGLE;
    setDriveBrake(hold);

    LeftDrive.spinFor(directionType::fwd, numberOfRevs*360, rotationUnits::deg, TURNING_VELOCITY, velocityUnits::pct, false);
    RightDrive.spinFor(directionType::rev, numberOfRevs*360, rotationUnits::deg, TURNING_VELOCITY, velocityUnits::pct);
    
    setDriveBrake(brake);
    wait(WAIT_AFTER_DRIVE, msec);
}



// ========= Arm Time-Based Functions ========= //
void armUpTime (int time){
    Arm.spin(directionType::fwd, ARM_VELOCITY, pct);
    wait(time, msec);   // Leave motor on for some 'time'

    // Turn motor off
    Arm.stop();

    wait(WAIT_AFTER_DRIVE, msec);
}

void armDownTime (int time){
    Arm.spin(directionType::rev, ARM_VELOCITY, pct);
    wait(time, msec);   // Leave motor on for some 'time'

    // Turn motor off
    Arm.stop();

    wait(WAIT_AFTER_DRIVE, msec);
}




// ========= Arm Encoder-Based Functions ========= //
void armUpEnc (float degrees){
    Arm.spinFor(directionType::fwd, degrees*7, rotationUnits::deg, ARM_VELOCITY, velocityUnits::pct);
}

void armDownEnc (float degrees){
    Arm.spinFor(directionType::rev, degrees*7, rotationUnits::deg, ARM_VELOCITY, velocityUnits::pct);
}




// =============== Claw Control =============== //
void clawOpen() {
    Claw.spin(directionType::fwd, CLAW_VELOCITY, pct);
    wait(300, msec);   // Leave motor on for some 'time'

    // Turn motor off
    Claw.stop();

    wait(WAIT_AFTER_DRIVE, msec);
}

void clawClose(){
    Claw.spin(directionType::rev, CLAW_VELOCITY, pct);
    wait(300, msec);   // Leave motor on for some 'time'

    // Turn motor off
    Claw.stop();

    wait(WAIT_AFTER_DRIVE, msec);
}