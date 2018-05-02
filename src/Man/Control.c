#pragma config(UserModel, "C:/Users/staff/Desktop/clawBot-master/src/plainClawBot.h")
#include "C:/Users/staff/Desktop/clawBot-master/src/Man/Headers/Control.h"

#define a		//a - auto, m - manual

task auto(){
	int state = 0;		//0 - FindCone
										//1 - Grab Cone
	////////Auto code////////
	while(true){
		switch(state){
		case 0:
			state = findCone();
		}
	}
	////////Auto code////////
}

void man(){
	stopTask(auto);
	startTask(checkArm);
	startTask(checkClaw);
	startTask(checkMove);
	startTask(checkBMot);
}

task main(){
	bool manOn;

#ifdef a
	manOn = false;
	startTask(auto);
#endif

#ifdef m	// man
	manOn = true;
	man();
#endif

	while(true){
		if((vexRT[Btn8D] == 1 && vexRT[Btn8R] == 1) && !manOn) {
			man();
			manOn = true;
			} else if ((vexRT[Btn8L] == 1 && vexRT[Btn8U] == 1) && manOn) {
			manOn = false;
			stopTask(checkArm);
			stopTask(checkClaw);
			stopTask(checkMove);
			startTask(auto);

		}
	}

}
