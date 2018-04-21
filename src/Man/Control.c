#pragma config(UserModel, "C:/Users/Andrew/Documents/Programing/RobotC/Projects/Testing/src/plainClawBot.h")
#include "C:/Users/Andrew/Documents/Programing/RobotC/Projects/Testing/src/Man/Headers/Control.h"

task main(){
	//Check in separate threads
	startTask(checkArm);
	startTask(checkClaw);

	while(true)
		checkMove();
}
