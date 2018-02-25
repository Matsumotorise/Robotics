#pragma config(UserModel, "C:/Users/Andrew/Documents/Programing/Robotc/Projects/Testing/src/Headers/plainClawBot.h")

#include "Header.h"

//////////////////Main method/////////////////////
task main() {
	move(100, 1200);
	wait1Msec(10);

	turn('L', 360);
}
/////////////////End Main method//////////////////
