# VEX-Robotics-2020
16099A VEX Robotics 2020 Code

To upload program to Robot, we used VEXCode to upload to the V5 Brain.

**Project Overkill**
Program features driver control code using 4-motor drive using Mecanum Wheels to strafe.
Includes lift control code as well as autonomous lift code.
Includes claw functions to grab game objects.
Sensors used: VEX Inertial Sensor, Gyroscope, Shaft Encoder and Potentiometer

PID functions are mostly in the drive function section.
The functions include a PID turn, PID move, and PID strafe.
The turning PID controller consists of a proportional-integral-derivative controller. The controller tries to minimize the error and noise for the robot to turn in a specific amount of time. The function uses the inertial sensor with the built-in gyroscope for its input. Sometimes the momentum of the robot would stray from the desired value. We limited the speed of the drive and tuned the PID controller to have less windup.

The moving PID controller only uses proportional-derivative controller. It uses the built-in encoder in the motor to track distance. This controller regulates the speed and distance of the motor. There were some drift at the end since the momentum can cause the robot to move farther than desired. We tuned the controller as best as we can but this function is not perfect since there are some errors left. 

**Claw Auto**
This program uses almost the same functions but there's an autonomous routine for the VEX Skills Competition. That part requires a 1-minute autonomous route. This route was intended for VEX Robotics 2020 Tower Takeover and the most points we achieved with this routine was 21 points.
