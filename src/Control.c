#pragma config(UserModel, "C:/Users/Andrew/Documents/Programing/RobotC/Projects/Testing/src/Headers/plainClawBot.h")

void checkMove(){
		motor[LMot] = vexRT[Ch3];
		motor[RMot] = vexRT[Ch3];
}

void checkClaw(){
		if(vexRT[Btn6U] == 1){
			motor[clawMot] = 127;
		} else if (vexRT[Btn6D] == 1) {
			motor[clawMot] = -127;
		} else {
			motor[clawMot] = 0;
		}
}

void checkTurn(){
	if(vexRT[Ch1] < 0){
		motor[LMot] = -vexRT[Ch1];
		motor[RMot] = vexRT[Ch1];
	} else {
		motor[LMot] = vexRT[Ch1];
		motor[RMot] = -vexRT[Ch1];
	}

}

task main(){
	//Inf loop
	while(true){
		checkMove();
		checkTurn();
		checkClaw();
	}
}
