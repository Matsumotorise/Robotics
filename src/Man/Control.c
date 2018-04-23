#pragma config(UserModel, "C:/Users/staff/Desktop/clawBot-master/src/plainClawBot.h")


#include "C:/Users/staff/Desktop/clawBot-master/src/Man/Headers/Control.h"


task main(){
	//Check in separate threads
	startTask(checkArm);
	startTask(checkClaw);

	while(true)
		checkMove();
}
