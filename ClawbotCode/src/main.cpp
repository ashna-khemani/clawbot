#include "vex.h"
#include "bot-functions.h"
using namespace vex;
competition Competition;

int filter (int value) {
  if (abs(value) > 16) {
    return (value);
  } else {
    return (0);
  }
}

// Pre-autonomous: do actions before competition starts, as soon as program/bot are turned on. Do not have a long loop!
void pre_auton(void) {
  mainControl.Screen.clearScreen();
  mainControl.Screen.print("I'M NOT A ROBOT.");
  Arm.setBrake(brakeType::hold);
  Claw.setBrake(brakeType::hold);
  setDriveBrake(brake);

}

// Autonomous code for robot to drive itself Use 'bot-functions' here
void autonomous(void) {
  
  # if 0
  // Time based auton
  clawClose();
  armUpTime(400);
  goFwdTime(1400, 50);
  clawOpen();
  goBackTime(1150, 50);
  # endif
  clawClose();
  armUpEnc(40);
  goFwdEnc(6, 25);
  clawOpen();
  goBackEnc(7, 25);
  // scored first block - everything above here is perfect code
  turnLeftEnc(90);
  armDownEnc(40);
  goFwdEnc(8, 15);
  wait(250, msec);
  clawClose();
  // grabbed second block
 goBackEnc(6, 25);
 turnRightEnc(90);
 armUpEnc(80);
 goFwdEnc(11, 25);
 armDownEnc(20);
 clawOpen();
 goBackEnc(7, 25);
 turnLeftEnc(90);
 armDownEnc(59);
 wait(250, msec);
 goFwdEnc(34, 20);
 clawClose();

 
  //second block complete
}

// Usercontrol code. Make bot respond to controller joysticks and buttons
void usercontrol(void) {
  Brain.Screen.newLine(); 
  Brain.Screen.print("User Control started!");
  int fwd, trn;
  int leftPwr, rightPwr;

  while (1) {

    // Drivetrain control - given here
    fwd = filter(mainControl.Axis3.position()) * DRIVE_WEIGHT;
    trn = filter(mainControl.Axis1.position()) * TURN_WEIGHT;
    leftPwr = (fwd + trn);
    rightPwr = (fwd - trn);

    LeftDrive.spin(vex::directionType::fwd, leftPwr, vex::velocityUnits::pct);
    RightDrive.spin(vex::directionType::fwd, rightPwr, vex::velocityUnits::pct);


    // Claw control - given here
    if (mainControl.ButtonL1.pressing()){
      Claw.spin(directionType::fwd, CLAW_VELOCITY, velocityUnits::pct);
    }
    else if (mainControl.ButtonL2.pressing()){
      Claw.spin(directionType::rev, CLAW_VELOCITY, velocityUnits::pct);
    }
    else{
      Claw.stop();
    }

    // Arm control - write it yourself!
      // Hint: very similar to claw control!
    if (mainControl.ButtonR1.pressing()){
      Arm.spin(directionType::fwd, ARM_VELOCITY, velocityUnits::pct);
    }
    else if (mainControl.ButtonR2.pressing()){
      Arm.spin(directionType::rev, ARM_VELOCITY, velocityUnits::pct);
    }
    else{
      Arm.stop();
    }
    

    wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}



// DO NOT EDIT BELOW THIS LINE

// Main will set up the competition functions and callbacks.
int main() {
  // Run autonomous and driver control periods with competition settings
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
