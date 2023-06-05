#include "vex.h"
#include "bot-functions.h"
using namespace vex;
competition Competition;



// Pre-autonomous: do actions before competition starts, as soon as program/bot are turned on. Do not have a long loop!
void pre_auton(void) {
  // insert pre-auton code here. Set brakes, print a message...
}

// Autonomous code for robot to drive itself Use 'bot-functions' here
void autonomous(void) {
  // insert auton code here (use functions from bot-functions!)
}

// Usercontrol code. Make bot respond to controller joysticks and buttons
void usercontrol(void) {
  Brain.Screen.newLine(); 
  Brain.Screen.print("User Control started!");
  int fwd, trn;
  int leftPwr, rightPwr;

  while (1) {

    // Drivetrain control - given here
    fwd = mainControl.Axis3.position();
    trn = mainControl.Axis1.position();
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
