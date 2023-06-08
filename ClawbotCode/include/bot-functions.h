// Constants
#define WHEEL_DIAMETER          4.0      // Wheel diameter in inches
#define WHEEL_CIRCUMFERENCE     (WHEEL_DIAMETER * 3.2) // Approx. pi ~ 3.2
#define TURNING_VELOCITY        50
#define REV_TO_ANGLE            1/110   //** NEED TO MEASURE THIS! -- done!
#define WAIT_AFTER_DRIVE        200
#define ARM_VELOCITY            70
#define CLAW_VELOCITY           55
#define DRIVE_WEIGHT            0.3
#define TURN_WEIGHT             0.3

// Declare electronics
extern vex::controller mainControl;
extern vex::brain Brain;
extern vex::motor LeftDrive;
extern vex::motor RightDrive;
extern vex::motor Arm;
extern vex::motor Claw;


// Declare robot operation functions

void setDriveBrake (vex::brakeType braking);

// Time-based drive
void goFwdTime (int time, int velocity);
void goBackTime (int time, int velocity);
void turnLeftTime (int time);
void turnRightTime (int time);

// Enc-based drive
void goFwdEnc (float inches, int velocity);
void goBackEnc (float inches, int velocity);
void turnLeftEnc (float degrees);
void turnRightEnc (float degrees);

// Arm control
void armUpTime (int time);
void armDownTime (int time);
void armUpEnc (float degrees);
void armDownEnc (float degrees);

// Claw control
void clawOpen();
void clawClose();