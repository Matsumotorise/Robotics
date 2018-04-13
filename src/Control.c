#pragma config(UserModel, "C:/Users/Andrew/Documents/Programing/RobotC/Projects/Testing/src/Headers/plainClawBot.h")

#include "C:/Users/Andrew/Documents/Programing/RobotC/Projects/Testing/src/Headers/Control.h"

task main(){
	//Check in separate threads
	startTask(checkArm);
	startTask(checkClaw);

	while(true)
		checkMove();
}
